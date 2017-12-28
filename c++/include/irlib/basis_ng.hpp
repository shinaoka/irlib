#pragma once

#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include <set>
#include <assert.h>
#include <memory>
#include <iomanip>
#include <fstream>

#include <Eigen/CXX11/Tensor>
#include <Eigen/MPRealSupport>

#include "common.hpp"
#include "kernel.hpp"
#include "piecewise_polynomial.hpp"

#include "detail/aux.hpp"

namespace irlib {

/**
 * Class representing kernel Ir basis
 */
    class basis {
    public:
        /**
         * Constructor
         * @param s  statistics
         * @param Lambda Lambda
         * @param sv singular values
         * @param u_basis piecewise polynomials representing u_l(x)
         * @param v_basis piecewise polynomials representing v_l(y)
         */
        basis(statistics::statistics_type s,
            double Lambda,
            const std::vector<double> &sv,
            const std::vector<piecewise_polynomial<double, mpfr::mpreal>> &u_basis,
            const std::vector<piecewise_polynomial<double, mpfr::mpreal>> &v_basis
        ) throw(std::runtime_error) {
            statistics_ = s;
            Lambda_ = Lambda;
            sv_ = sv;
            u_basis_ = u_basis;
            v_basis_ = v_basis;
        }

    private:
        statistics::statistics_type statistics_;
        double Lambda_;
        std::vector<double> sv_;
        std::vector<piecewise_polynomial<double, mpfr::mpreal>> u_basis_, v_basis_;

    public:
        /**
         * Compute the values of the basis functions for a given x.
         * @param x    x = 2 * tau/beta - 1  (-1 <= x <= 1)
         * @param val  results
         */
        double sl(int l) const throw(std::runtime_error) {
            assert(l >= 0 && l < dim());
            python_runtime_check(l >= 0 && l < dim(), "Index l is out of range.");
            return sv_[l];
        }

        double Lambda() const {
            return Lambda_;
        }

        /**
         * @param l  order of basis function
         * @param x  x on [-1,1]
         * @return   The value of u_l(x)
         */
        double ulx(int l, double x) const throw(std::runtime_error) {
            assert(x >= -1 && x <= 1);
            assert(l >= 0 && l < dim());
            return ulx_mp(l, mpfr::mpreal(x));
        }

        /**
         * @param l  order of basis function
         * @param y  y on [-1,1]
         * @return   The value of v_l(y)
         */
        double vly(int l, double y) const throw(std::runtime_error) {
            assert(y >= -1 && y <= 1);
            assert(l >= 0 && l < dim());
            return vly_mp(l, mpfr::mpreal(y));
        }

        /**
         * This function should not be called outside this library
         * @param l  order of basis function
         * @param x  x on [-1,1]
         * @return   The value of u_l(x)
         */
        double ulx_mp(int l, const mpfr::mpreal &x) const throw(std::runtime_error) {
            assert(x >= -1 && x <= 1);
            assert(l >= 0 && l < dim());
            python_runtime_check(l >= 0 && l < dim(), "Index l is out of range.");
            python_runtime_check(x >= -1 && x <= 1, "x must be in [-1,1].");

            if (x >= 0) {
                return u_basis_[l].compute_value(x);
            } else {
                return u_basis_[l].compute_value(-x) * (l % 2 == 0 ? 1 : -1);
            }
        }

        /**
         * This function should not be called outside this library
         * @param l  order of basis function
         * @param y  y on [-1,1]
         * @return   The value of v_l(y)
         */
        double vly_mp(int l, const mpfr::mpreal &y) const throw(std::runtime_error) {
            assert(y >= -1 && y <= 1);
            assert(l >= 0 && l < dim());
            python_runtime_check(l >= 0 && l < dim(), "Index l is out of range.");
            python_runtime_check(y >= -1 && y <= 1, "y must be in [-1,1].");
            if (y >= 0) {
                return v_basis_[l].compute_value(y);
            } else {
                return v_basis_[l].compute_value(-y) * (l % 2 == 0 ? 1 : -1);
            }
        }

        /**
         * Return a reference to the l-th basis function
         * @param l l-th basis function
         * @return  reference to the l-th basis function
         */
        const piecewise_polynomial<double, mpfr::mpreal> &ul(int l) const throw(std::runtime_error) {
            assert(l >= 0 && l < dim());
            python_runtime_check(l >= 0 && l < dim(), "Index l is out of range.");
            return u_basis_[l];
        }

        const piecewise_polynomial<double, mpfr::mpreal> &vl(int l) const throw(std::runtime_error) {
            assert(l >= 0 && l < dim());
            python_runtime_check(l >= 0 && l < dim(), "Index l is out of range.");
            return v_basis_[l];
        }

        /**
         * Return number of basis functions
         * @return  number of basis functions
         */
        int dim() const { return u_basis_.size(); }

        /// Return statistics
        irlib::statistics::statistics_type get_statistics() const {
            return statistics_;
        }

#ifndef SWIG //DO NOT EXPOSE TO PYTHON

        /**
         * Compute transformation matrix to Matsubara freq.
         * The computation may take some time. You may store the result somewhere and do not call this routine frequenctly.
         * @param n_vec  This vector must contain indices of Matsubara freqencies
         * @param Tnl    Results
         */
        void compute_Tnl(
                const std::vector<long> &n_vec,
                Eigen::Tensor<std::complex<double>, 2> &Tnl
        ) const {
            auto trans_to_non_negative = [&](long n) {
                if (n >= 0) {
                    return n;
                } else {
                    if (statistics_ == irlib::statistics::FERMIONIC) {
                        return -n - 1;
                    } else {
                        return -n;
                    }
                }
            };

            auto nl = dim();

            std::set<long> none_negative_n;
            for (const auto &n : n_vec) {
                none_negative_n.insert(trans_to_non_negative(n));
            }

            Eigen::Tensor<std::complex<double>, 2> Tnl_tmp;
            compute_transformation_matrix_to_matsubara<double>(
                    std::vector<long>(none_negative_n.begin(), none_negative_n.end()),
                    statistics_, u_basis_, Tnl_tmp
            );

            Tnl = Eigen::Tensor<std::complex<double>, 2>(n_vec.size(), nl);
            for (int i = 0; i < n_vec.size(); ++i) {
                auto index_data = std::distance(
                        none_negative_n.begin(),
                        none_negative_n.find(trans_to_non_negative(n_vec[i]))
                );
                if (n_vec[i] >= 0) {
                    for (int l = 0; l < nl; ++l) {
                        Tnl(i, l) = Tnl_tmp(index_data, l);
                    }
                } else {
                    for (int l = 0; l < nl; ++l) {
                        Tnl(i, l) = std::conj(Tnl_tmp(index_data, l));
                    }
                }
            }
        }

#endif

        /**
         * Compute transformation matrix to Matsubara freq.
         * The computation may take some time. You may store the result somewhere and do not call this routine frequenctly.
         * @param n_vec  This vector must contain indices of Matsubara freqencies
         * @return Results
         */
        Eigen::Tensor<std::complex<double>, 2>
        compute_Tnl(const std::vector<long> &n_vec) const {
            Eigen::Tensor<std::complex<double>, 2> Tnl;
            compute_Tnl(n_vec, Tnl);
            return Tnl;
        }

    };

    basis compute_basis(statistics::statistics_type s,
                        double Lambda,
                        int max_dim = 1000,
                        double cutoff = 1e-8,
                        int n_local_poly = 10,
                        const std::string& fp_mode="mp") throw(std::runtime_error) {

        std::vector<double> sv;
        std::vector<piecewise_polynomial<double, mpfr::mpreal>> u_basis;
        std::vector<piecewise_polynomial<double, mpfr::mpreal>> v_basis;

        if (fp_mode == "mp") {
            // Increase default precision if needed
            {
                auto min_prec = std::max(
                        mpfr::digits2bits(std::log10(1/cutoff))+10,
                        long(64)//At least 19 digits
                );
                if (min_prec > mpfr::mpreal::get_default_prec()) {
                    mpfr::mpreal::set_default_prec(min_prec);
                }
            }
            if (s == statistics::FERMIONIC) {
                std::tie(sv, u_basis, v_basis) = generate_ir_basis_functions<mpfr::mpreal>(
                        fermionic_kernel<mpfr::mpreal>(Lambda), max_dim, cutoff, n_local_poly);
            } else if (s == statistics::BOSONIC) {
                std::tie(sv, u_basis, v_basis) = generate_ir_basis_functions<mpfr::mpreal>(
                        bosonic_kernel<mpfr::mpreal>(Lambda), max_dim, cutoff, n_local_poly);
            }
        } else if (fp_mode == "long double") {
            if (cutoff < 1e-8) {
                throw std::runtime_error("cutoff cannot be smaller than 1e-8 for long-double precision version. Please use fp_mode='mp'!");
            }
            if (s == statistics::FERMIONIC) {
                std::tie(sv, u_basis, v_basis) = generate_ir_basis_functions<long double>(
                        fermionic_kernel<mpfr::mpreal>(Lambda), max_dim, cutoff, n_local_poly);
            } else if (s == statistics::BOSONIC) {
                std::tie(sv, u_basis, v_basis) = generate_ir_basis_functions<long double>(
                        bosonic_kernel<mpfr::mpreal>(Lambda), max_dim, cutoff, n_local_poly);
            }
        } else {
            throw std::runtime_error("Unknown fp_mode " + fp_mode + ". Only 'mp' and 'long double' are supported.");
        }

        return basis(s, Lambda, sv, u_basis, v_basis);
    }

    inline void savetxt(const std::string& fname, const basis& b) {
        std::ofstream ofs(fname);

        ofs << b.get_statistics() << std::endl;
        ofs << b.Lambda() << std::endl;
        ofs << b.dim() << std::endl;
        for (int l=0; l<b.dim(); ++l) {
            ofs << std::setprecision(20) << b.sl(l) << std::endl;
        }
        for (int l=0; l<b.dim(); ++l) {
            ofs << b.ul(l);
        }
        for (int l=0; l<b.dim(); ++l) {
            ofs << b.vl(l);
        }
    }

    inline basis loadtxt(const std::string& fname) {
        std::ifstream ifs(fname);

        statistics::statistics_type s;
        double Lambda;
        int dim;

        {
            int itmp;
            ifs >> itmp;
            s = static_cast<statistics::statistics_type>(itmp);
        }
        ifs >> Lambda;
        ifs >> dim;

        std::vector<double> sv(dim);
        for (int l=0; l<dim; ++l) {
            ifs >> sv[l];
        }

        std::vector<piecewise_polynomial<double, mpfr::mpreal>> u_basis(dim), v_basis(dim);

        for (int l=0; l<dim; ++l) {
            ifs >> u_basis[l];
        }

        for (int l=0; l<dim; ++l) {
            ifs >> v_basis[l];
        }

        return basis(s, Lambda, sv, u_basis, v_basis);
    }
}
