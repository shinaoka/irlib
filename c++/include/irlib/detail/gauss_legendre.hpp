
#pragma once

#include <vector>
#include <string>
#include <utility>

namespace irlib {
namespace detail {

template<typename S>
S stoscalar(const std::string& s);

template<>
double stoscalar<double>(const std::string& s) {
   return std::stof(s);
}

template<>
mpfr::mpreal stoscalar<mpfr::mpreal>(const std::string& s) {
   return mpfr::mpreal(s);
}

template<typename T>
std::vector<std::pair<T,T>>
gauss_legendre_nodes(int num_nodes) {


    if (num_nodes == 6) {
        std::vector<std::pair<T,T>> nodes(6);

        nodes[0] = std::make_pair<T>(stoscalar<T>("0.93246951420315202781230155449399460913476573771229"), stoscalar<T>("0.17132449237917034504029614217273289352682250148404"));
        nodes[1] = std::make_pair<T>(stoscalar<T>("-0.93246951420315202781230155449399460913476573771229"), stoscalar<T>("0.17132449237917034504029614217273289352682250148404"));
        nodes[2] = std::make_pair<T>(stoscalar<T>("0.66120938646626451366139959501990534700644856439517"), stoscalar<T>("0.36076157304813860756983351383771611166152189274675"));
        nodes[3] = std::make_pair<T>(stoscalar<T>("-0.66120938646626451366139959501990534700644856439517"), stoscalar<T>("0.36076157304813860756983351383771611166152189274675"));
        nodes[4] = std::make_pair<T>(stoscalar<T>("0.23861918608319690863050172168071193541861063014002"), stoscalar<T>("0.46791393457269104738987034398955099481165560576921"));
        nodes[5] = std::make_pair<T>(stoscalar<T>("-0.23861918608319690863050172168071193541861063014002"), stoscalar<T>("0.46791393457269104738987034398955099481165560576921"));

        return nodes;
    }


    if (num_nodes == 12) {
        std::vector<std::pair<T,T>> nodes(12);

        nodes[0] = std::make_pair<T>(stoscalar<T>("0.98156063424671925069054909014928082296015519981373"), stoscalar<T>("0.047175336386511827194615961485017060317029073994847"));
        nodes[1] = std::make_pair<T>(stoscalar<T>("-0.98156063424671925069054909014928082296015519981373"), stoscalar<T>("0.047175336386511827194615961485017060317029073994847"));
        nodes[2] = std::make_pair<T>(stoscalar<T>("0.9041172563704748566784658661190961925375967092133"), stoscalar<T>("0.10693932599531843096025471819399622421457017347032"));
        nodes[3] = std::make_pair<T>(stoscalar<T>("-0.9041172563704748566784658661190961925375967092133"), stoscalar<T>("0.10693932599531843096025471819399622421457017347032"));
        nodes[4] = std::make_pair<T>(stoscalar<T>("0.76990267419430468703689383321281807598492575001893"), stoscalar<T>("0.16007832854334622633465252954335907187201173049086"));
        nodes[5] = std::make_pair<T>(stoscalar<T>("-0.76990267419430468703689383321281807598492575001893"), stoscalar<T>("0.16007832854334622633465252954335907187201173049086"));
        nodes[6] = std::make_pair<T>(stoscalar<T>("0.58731795428661744729670241894053428036909851404805"), stoscalar<T>("0.20316742672306592174906445580979837650651814727459"));
        nodes[7] = std::make_pair<T>(stoscalar<T>("-0.58731795428661744729670241894053428036909851404805"), stoscalar<T>("0.20316742672306592174906445580979837650651814727459"));
        nodes[8] = std::make_pair<T>(stoscalar<T>("0.36783149899818019375269153664371756125636014133541"), stoscalar<T>("0.23349253653835480876084989892487805625940997219975"));
        nodes[9] = std::make_pair<T>(stoscalar<T>("-0.36783149899818019375269153664371756125636014133541"), stoscalar<T>("0.23349253653835480876084989892487805625940997219975"));
        nodes[10] = std::make_pair<T>(stoscalar<T>("0.12523340851146891547244136946385312998339691630544"), stoscalar<T>("0.24914704581340278500056243604295121083046090256962"));
        nodes[11] = std::make_pair<T>(stoscalar<T>("-0.12523340851146891547244136946385312998339691630544"), stoscalar<T>("0.24914704581340278500056243604295121083046090256962"));

        return nodes;
    }


    if (num_nodes == 24) {
        std::vector<std::pair<T,T>> nodes(24);

        nodes[0] = std::make_pair<T>(stoscalar<T>("0.995187219997021360179997409700736811874597692596"), stoscalar<T>("0.012341229799987199546805667070037291575910040891367"));
        nodes[1] = std::make_pair<T>(stoscalar<T>("-0.995187219997021360179997409700736811874597692596"), stoscalar<T>("0.012341229799987199546805667070037291575910040891367"));
        nodes[2] = std::make_pair<T>(stoscalar<T>("0.97472855597130949819839199300816906174118305304018"), stoscalar<T>("0.028531388628933663181307815951878286449197797931908"));
        nodes[3] = std::make_pair<T>(stoscalar<T>("-0.97472855597130949819839199300816906174118305304018"), stoscalar<T>("0.028531388628933663181307815951878286449197797931908"));
        nodes[4] = std::make_pair<T>(stoscalar<T>("0.93827455200273275852364900170872144965481965807745"), stoscalar<T>("0.044277438817419806168602748211338228859312841833858"));
        nodes[5] = std::make_pair<T>(stoscalar<T>("-0.93827455200273275852364900170872144965481965807745"), stoscalar<T>("0.044277438817419806168602748211338228859312841833858"));
        nodes[6] = std::make_pair<T>(stoscalar<T>("0.88641552700440103421315434198219675508733304330892"), stoscalar<T>("0.059298584915436780746367758500108584541200126565213"));
        nodes[7] = std::make_pair<T>(stoscalar<T>("-0.88641552700440103421315434198219675508733304330892"), stoscalar<T>("0.059298584915436780746367758500108584541200126565213"));
        nodes[8] = std::make_pair<T>(stoscalar<T>("0.82000198597390292195394987266974520807612647766786"), stoscalar<T>("0.073346481411080305734033615253116518119336509848499"));
        nodes[9] = std::make_pair<T>(stoscalar<T>("-0.82000198597390292195394987266974520807612647766786"), stoscalar<T>("0.073346481411080305734033615253116518119336509848499"));
        nodes[10] = std::make_pair<T>(stoscalar<T>("0.74012419157855436424382810309997842552329248701419"), stoscalar<T>("0.086190161531953275917185202983742667185080588237933"));
        nodes[11] = std::make_pair<T>(stoscalar<T>("-0.74012419157855436424382810309997842552329248701419"), stoscalar<T>("0.086190161531953275917185202983742667185080588237933"));
        nodes[12] = std::make_pair<T>(stoscalar<T>("0.64809365193697556925249578691074762666965829861896"), stoscalar<T>("0.097618652104113888269880664464247154427918968853686"));
        nodes[13] = std::make_pair<T>(stoscalar<T>("-0.64809365193697556925249578691074762666965829861896"), stoscalar<T>("0.097618652104113888269880664464247154427918968853686"));
        nodes[14] = std::make_pair<T>(stoscalar<T>("0.54542147138883953565837561721837237001078399258762"), stoscalar<T>("0.10744427011596563478257734244660622279462869013422"));
        nodes[15] = std::make_pair<T>(stoscalar<T>("-0.54542147138883953565837561721837237001078399258762"), stoscalar<T>("0.10744427011596563478257734244660622279462869013422"));
        nodes[16] = std::make_pair<T>(stoscalar<T>("0.43379350762604513848708423191334971245242151092797"), stoscalar<T>("0.1155056680537256013533444839067835598622703113765"));
        nodes[17] = std::make_pair<T>(stoscalar<T>("-0.43379350762604513848708423191334971245242151092797"), stoscalar<T>("0.1155056680537256013533444839067835598622703113765"));
        nodes[18] = std::make_pair<T>(stoscalar<T>("0.31504267969616337438679329131981024078647826082482"), stoscalar<T>("0.12167047292780339120446315347626242560702955920381"));
        nodes[19] = std::make_pair<T>(stoscalar<T>("-0.31504267969616337438679329131981024078647826082482"), stoscalar<T>("0.12167047292780339120446315347626242560702955920381"));
        nodes[20] = std::make_pair<T>(stoscalar<T>("0.19111886747361630915863982075706963184040510331475"), stoscalar<T>("0.12583745634682829612137538251118368872640332558135"));
        nodes[21] = std::make_pair<T>(stoscalar<T>("-0.19111886747361630915863982075706963184040510331475"), stoscalar<T>("0.12583745634682829612137538251118368872640332558135"));
        nodes[22] = std::make_pair<T>(stoscalar<T>("0.064056892862605626085043082624745038590999195420747"), stoscalar<T>("0.12793819534675215697405616522469537185171123954167"));
        nodes[23] = std::make_pair<T>(stoscalar<T>("-0.064056892862605626085043082624745038590999195420747"), stoscalar<T>("0.12793819534675215697405616522469537185171123954167"));

        return nodes;
    }


    if (num_nodes == 48) {
        std::vector<std::pair<T,T>> nodes(48);

        nodes[0] = std::make_pair<T>(stoscalar<T>("0.99877100725242611860054149156311364008893765027672"), stoscalar<T>("0.0031533460523058386326773115438914875782839388316936"));
        nodes[1] = std::make_pair<T>(stoscalar<T>("-0.99877100725242611860054149156311364008893765027672"), stoscalar<T>("0.0031533460523058386326773115438914875782839388316936"));
        nodes[2] = std::make_pair<T>(stoscalar<T>("0.99353017226635075754792875084907411835661474959467"), stoscalar<T>("0.0073275539012762621023839796217865500587079025592014"));
        nodes[3] = std::make_pair<T>(stoscalar<T>("-0.99353017226635075754792875084907411835661474959467"), stoscalar<T>("0.0073275539012762621023839796217865500587079025592014"));
        nodes[4] = std::make_pair<T>(stoscalar<T>("0.98412458372282685774458360002659883058923922341738"), stoscalar<T>("0.011477234579234539489592667609091628086420506308748"));
        nodes[5] = std::make_pair<T>(stoscalar<T>("-0.98412458372282685774458360002659883058923922341738"), stoscalar<T>("0.011477234579234539489592667609091628086420506308748"));
        nodes[6] = std::make_pair<T>(stoscalar<T>("0.97059159254624725046141198380066005730243391163088"), stoscalar<T>("0.015579315722943848728176955834460313976376268991552"));
        nodes[7] = std::make_pair<T>(stoscalar<T>("-0.97059159254624725046141198380066005730243391163088"), stoscalar<T>("0.015579315722943848728176955834460313976376268991552"));
        nodes[8] = std::make_pair<T>(stoscalar<T>("0.95298770316043086072296066602571834320854133182392"), stoscalar<T>("0.019616160457355527814460719652212709695813037734132"));
        nodes[9] = std::make_pair<T>(stoscalar<T>("-0.95298770316043086072296066602571834320854133182392"), stoscalar<T>("0.019616160457355527814460719652212709695813037734132"));
        nodes[10] = std::make_pair<T>(stoscalar<T>("0.93138669070655433311417438010160126771999708561895"), stoscalar<T>("0.023570760839324379140519301378449230221729738522189"));
        nodes[11] = std::make_pair<T>(stoscalar<T>("-0.93138669070655433311417438010160126771999708561895"), stoscalar<T>("0.023570760839324379140519301378449230221729738522189"));
        nodes[12] = std::make_pair<T>(stoscalar<T>("0.90587913671556967282207483567101178831226219982741"), stoscalar<T>("0.027426509708356948200073836262505820451184155161651"));
        nodes[13] = std::make_pair<T>(stoscalar<T>("-0.90587913671556967282207483567101178831226219982741"), stoscalar<T>("0.027426509708356948200073836262505820451184155161651"));
        nodes[14] = std::make_pair<T>(stoscalar<T>("0.87657202027424788590569355480509675456164853372996"), stoscalar<T>("0.03116722783279808890206575684635441945428534148357"));
        nodes[15] = std::make_pair<T>(stoscalar<T>("-0.87657202027424788590569355480509675456164853372996"), stoscalar<T>("0.03116722783279808890206575684635441945428534148357"));
        nodes[16] = std::make_pair<T>(stoscalar<T>("0.84358826162439353071108984451965604987088701173755"), stoscalar<T>("0.034777222564770438892548585963802410597281396907068"));
        nodes[17] = std::make_pair<T>(stoscalar<T>("-0.84358826162439353071108984451965604987088701173755"), stoscalar<T>("0.034777222564770438892548585963802410597281396907068"));
        nodes[18] = std::make_pair<T>(stoscalar<T>("0.80706620402944262708255304302453844597301302946042"), stoscalar<T>("0.038241351065830706317217256523715617863823968354982"));
        nodes[19] = std::make_pair<T>(stoscalar<T>("-0.80706620402944262708255304302453844597301302946042"), stoscalar<T>("0.038241351065830706317217256523715617863823968354982"));
        nodes[20] = std::make_pair<T>(stoscalar<T>("0.76715903251574033925385543752296905362264233084821"), stoscalar<T>("0.041545082943464749214058822361064797753472826034038"));
        nodes[21] = std::make_pair<T>(stoscalar<T>("-0.76715903251574033925385543752296905362264233084821"), stoscalar<T>("0.041545082943464749214058822361064797753472826034038"));
        nodes[22] = std::make_pair<T>(stoscalar<T>("0.72403413092381465467448223349366524658509281228072"), stoscalar<T>("0.044674560856694280419448587125850394988462786862502"));
        nodes[23] = std::make_pair<T>(stoscalar<T>("-0.72403413092381465467448223349366524658509281228072"), stoscalar<T>("0.044674560856694280419448587125850394988462786862502"));
        nodes[24] = std::make_pair<T>(stoscalar<T>("0.67787237963266390521185128067590905884995467902605"), stoscalar<T>("0.04761665849249047482590662347892983015799806674345"));
        nodes[25] = std::make_pair<T>(stoscalar<T>("-0.67787237963266390521185128067590905884995467902605"), stoscalar<T>("0.04761665849249047482590662347892983015799806674345"));
        nodes[26] = std::make_pair<T>(stoscalar<T>("0.62886739677651362399516493306999465202490899979016"), stoscalar<T>("0.050359035553854474957807619087865606032994093025906"));
        nodes[27] = std::make_pair<T>(stoscalar<T>("-0.62886739677651362399516493306999465202490899979016"), stoscalar<T>("0.050359035553854474957807619087865606032994093025906"));
        nodes[28] = std::make_pair<T>(stoscalar<T>("0.5772247260839727038178092385404787728539972861402"), stoscalar<T>("0.052890189485193667095505056264698914661726485633109"));
        nodes[29] = std::make_pair<T>(stoscalar<T>("-0.5772247260839727038178092385404787728539972861402"), stoscalar<T>("0.052890189485193667095505056264698914661726485633109"));
        nodes[30] = std::make_pair<T>(stoscalar<T>("0.52316097472223303367822586913750852628918762181188"), stoscalar<T>("0.055199503699984162868203495191635439004450925607561"));
        nodes[31] = std::make_pair<T>(stoscalar<T>("-0.52316097472223303367822586913750852628918762181188"), stoscalar<T>("0.055199503699984162868203495191635439004450925607561"));
        nodes[32] = std::make_pair<T>(stoscalar<T>("0.46690290475095840454492886165079850923681210425852"), stoscalar<T>("0.057277292100403215705150234684700576241527123004112"));
        nodes[33] = std::make_pair<T>(stoscalar<T>("-0.46690290475095840454492886165079850923681210425852"), stoscalar<T>("0.057277292100403215705150234684700576241527123004112"));
        nodes[34] = std::make_pair<T>(stoscalar<T>("0.40868648199071672991622549581463328645992284299489"), stoscalar<T>("0.059114839698395635746474817433519910659655602557055"));
        nodes[35] = std::make_pair<T>(stoscalar<T>("-0.40868648199071672991622549581463328645992284299489"), stoscalar<T>("0.059114839698395635746474817433519910659655602557055"));
        nodes[36] = std::make_pair<T>(stoscalar<T>("0.34875588629216073815981793727040791613430964996839"), stoscalar<T>("0.060704439165893880052969232027820477885260864256478"));
        nodes[37] = std::make_pair<T>(stoscalar<T>("-0.34875588629216073815981793727040791613430964996839"), stoscalar<T>("0.060704439165893880052969232027820477885260864256478"));
        nodes[38] = std::make_pair<T>(stoscalar<T>("0.28736248735545557673588646131679768785155830580104"), stoscalar<T>("0.062039423159892663904197784137598518306383399665091"));
        nodes[39] = std::make_pair<T>(stoscalar<T>("-0.28736248735545557673588646131679768785155830580104"), stoscalar<T>("0.062039423159892663904197784137598518306383399665091"));
        nodes[40] = std::make_pair<T>(stoscalar<T>("0.22476379039468906122486544017469227743856180404165"), stoscalar<T>("0.063114192286254025657126022750233318127413643371101"));
        nodes[41] = std::make_pair<T>(stoscalar<T>("-0.22476379039468906122486544017469227743856180404165"), stoscalar<T>("0.063114192286254025657126022750233318127413643371101"));
        nodes[42] = std::make_pair<T>(stoscalar<T>("0.1612223560688917180564373907834976947743743797419"), stoscalar<T>("0.063924238584648186623906201825515408918974084982643"));
        nodes[43] = std::make_pair<T>(stoscalar<T>("-0.1612223560688917180564373907834976947743743797419"), stoscalar<T>("0.063924238584648186623906201825515408918974084982643"));
        nodes[44] = std::make_pair<T>(stoscalar<T>("0.097004699209462698930053955853624520152736229300937"), stoscalar<T>("0.06446616443595008220650419365770506572569192445553"));
        nodes[45] = std::make_pair<T>(stoscalar<T>("-0.097004699209462698930053955853624520152736229300937"), stoscalar<T>("0.06446616443595008220650419365770506572569192445553"));
        nodes[46] = std::make_pair<T>(stoscalar<T>("0.032380170962869362033322243152134442045962802361518"), stoscalar<T>("0.064737696812683922503024938736591553552081918946637"));
        nodes[47] = std::make_pair<T>(stoscalar<T>("-0.032380170962869362033322243152134442045962802361518"), stoscalar<T>("0.064737696812683922503024938736591553552081918946637"));

        return nodes;
    }


    if (num_nodes == 96) {
        std::vector<std::pair<T,T>> nodes(96);

        nodes[0] = std::make_pair<T>(stoscalar<T>("0.99968950388323076682769010578436551928154546273246"), stoscalar<T>("0.00079679206555201242943814349694356875993108692282687"));
        nodes[1] = std::make_pair<T>(stoscalar<T>("-0.99968950388323076682769010578436551928154546273246"), stoscalar<T>("0.00079679206555201242943814349694356875993108692282687"));
        nodes[2] = std::make_pair<T>(stoscalar<T>("0.99836437586318167772414943952671936338759413983573"), stoscalar<T>("0.0018539607889469217323359253508939105882082883762772"));
        nodes[3] = std::make_pair<T>(stoscalar<T>("-0.99836437586318167772414943952671936338759413983573"), stoscalar<T>("0.0018539607889469217323359253508939105882082883762772"));
        nodes[4] = std::make_pair<T>(stoscalar<T>("0.99598184298720929065039908487935660051740255920916"), stoscalar<T>("0.0029107318179349464084106179894007250097471693372343"));
        nodes[5] = std::make_pair<T>(stoscalar<T>("-0.99598184298720929065039908487935660051740255920916"), stoscalar<T>("0.0029107318179349464084106179894007250097471693372343"));
        nodes[6] = std::make_pair<T>(stoscalar<T>("0.99254390032376262457189229770160114087692506973571"), stoscalar<T>("0.0039645543384446866737334157674196598776912479228659"));
        nodes[7] = std::make_pair<T>(stoscalar<T>("-0.99254390032376262457189229770160114087692506973571"), stoscalar<T>("0.0039645543384446866737334157674196598776912479228659"));
        nodes[8] = std::make_pair<T>(stoscalar<T>("0.98805412632962379948076277241845119455046460061415"), stoscalar<T>("0.0050142027429275176924701949690308984740741124738811"));
        nodes[9] = std::make_pair<T>(stoscalar<T>("-0.98805412632962379948076277241845119455046460061415"), stoscalar<T>("0.0050142027429275176924701949690308984740741124738811"));
        nodes[10] = std::make_pair<T>(stoscalar<T>("0.98251726356301467744704583188254811794497581309072"), stoscalar<T>("0.0060585455042359616833167420317290879695781512093561"));
        nodes[11] = std::make_pair<T>(stoscalar<T>("-0.98251726356301467744704583188254811794497581309072"), stoscalar<T>("0.0060585455042359616833167420317290879695781512093561"));
        nodes[12] = std::make_pair<T>(stoscalar<T>("0.97593917458513646645260103424187990919840295459612"), stoscalar<T>("0.0070964707911538652691441608121433919347720993046936"));
        nodes[13] = std::make_pair<T>(stoscalar<T>("-0.97593917458513646645260103424187990919840295459612"), stoscalar<T>("0.0070964707911538652691441608121433919347720993046936"));
        nodes[14] = std::make_pair<T>(stoscalar<T>("0.96832682846326421217365936644365105839264424809452"), stoscalar<T>("0.0081268769256987592173824277078559377342447603208382"));
        nodes[15] = std::make_pair<T>(stoscalar<T>("-0.96832682846326421217365936644365105839264424809452"), stoscalar<T>("0.0081268769256987592173824277078559377342447603208382"));
        nodes[16] = std::make_pair<T>(stoscalar<T>("0.95968829144874253930006802588473474118734836647121"), stoscalar<T>("0.0091486712307833866325846026652079285264488019711332"));
        nodes[17] = std::make_pair<T>(stoscalar<T>("-0.95968829144874253930006802588473474118734836647121"), stoscalar<T>("0.0091486712307833866325846026652079285264488019711332"));
        nodes[18] = std::make_pair<T>(stoscalar<T>("0.95003271778443763575609894844386348780971900450686"), stoscalar<T>("0.010160770535008415757587636953825368848984845861046"));
        nodes[19] = std::make_pair<T>(stoscalar<T>("-0.95003271778443763575609894844386348780971900450686"), stoscalar<T>("0.010160770535008415757587636953825368848984845861046"));
        nodes[20] = std::make_pair<T>(stoscalar<T>("0.93937033975275521693185737943161521835526814705005"), stoscalar<T>("0.011162102099838498591213263828562068610863963422178"));
        nodes[21] = std::make_pair<T>(stoscalar<T>("-0.93937033975275521693185737943161521835526814705005"), stoscalar<T>("0.011162102099838498591213263828562068610863963422178"));
        nodes[22] = std::make_pair<T>(stoscalar<T>("0.92771245672230869096469047269654638690578248570143"), stoscalar<T>("0.012151604671088319635181352736667252122370643850579"));
        nodes[23] = std::make_pair<T>(stoscalar<T>("-0.92771245672230869096469047269654638690578248570143"), stoscalar<T>("0.012151604671088319635181352736667252122370643850579"));
        nodes[24] = std::make_pair<T>(stoscalar<T>("0.9150714231208980742058844661504215420870764189055"), stoscalar<T>("0.013128229566961572637063666902599108898775699313008"));
        nodes[25] = std::make_pair<T>(stoscalar<T>("-0.9150714231208980742058844661504215420870764189055"), stoscalar<T>("0.013128229566961572637063666902599108898775699313008"));
        nodes[26] = std::make_pair<T>(stoscalar<T>("0.90146063531585234131923269730968683784087137974048"), stoscalar<T>("0.014090941772314860915861624724636639518392151037111"));
        nodes[27] = std::make_pair<T>(stoscalar<T>("-0.90146063531585234131923269730968683784087137974048"), stoscalar<T>("0.014090941772314860915861624724636639518392151037111"));
        nodes[28] = std::make_pair<T>(stoscalar<T>("0.88689451740242041605687743339378615883199264504023"), stoscalar<T>("0.015038721026994938005876275222097552837384833970636"));
        nodes[29] = std::make_pair<T>(stoscalar<T>("-0.88689451740242041605687743339378615883199264504023"), stoscalar<T>("0.015038721026994938005876275222097552837384833970636"));
        nodes[30] = std::make_pair<T>(stoscalar<T>("0.87138850590929650287377476449304271472319863712707"), stoscalar<T>("0.015970562902562291380616456791493051060991482709337"));
        nodes[31] = std::make_pair<T>(stoscalar<T>("-0.87138850590929650287377476449304271472319863712707"), stoscalar<T>("0.015970562902562291380616456791493051060991482709337"));
        nodes[32] = std::make_pair<T>(stoscalar<T>("0.854959033434601455462786969893569260642796030026"), stoscalar<T>("0.016885479864245172450477540606861926652599614120811"));
        nodes[33] = std::make_pair<T>(stoscalar<T>("-0.854959033434601455462786969893569260642796030026"), stoscalar<T>("0.016885479864245172450477540606861926652599614120811"));
        nodes[34] = std::make_pair<T>(stoscalar<T>("0.837623511228187121494302816764692856979480843148"), stoscalar<T>("0.017782502316045260837614226486071016063899239907907"));
        nodes[35] = std::make_pair<T>(stoscalar<T>("-0.837623511228187121494302816764692856979480843148"), stoscalar<T>("0.017782502316045260837614226486071016063899239907907"));
        nodes[36] = std::make_pair<T>(stoscalar<T>("0.81940031073793167553899962422447803513534721938361"), stoscalar<T>("0.018660679627411467385156758622132219064144051709282"));
        nodes[37] = std::make_pair<T>(stoscalar<T>("-0.81940031073793167553899962422447803513534721938361"), stoscalar<T>("0.018660679627411467385156758622132219064144051709282"));
        nodes[38] = std::make_pair<T>(stoscalar<T>("0.80030874413914081722879614397132768321645557542642"), stoscalar<T>("0.019519081140145022410085220281204686487858881013737"));
        nodes[39] = std::make_pair<T>(stoscalar<T>("-0.80030874413914081722879614397132768321645557542642"), stoscalar<T>("0.019519081140145022410085220281204686487858881013737"));
        nodes[40] = std::make_pair<T>(stoscalar<T>("0.78036904386743321760360445588931774802018338143591"), stoscalar<T>("0.020356797154333324595245215417271614342068969553952"));
        nodes[41] = std::make_pair<T>(stoscalar<T>("-0.78036904386743321760360445588931774802018338143591"), stoscalar<T>("0.020356797154333324595245215417271614342068969553952"));
        nodes[42] = std::make_pair<T>(stoscalar<T>("0.75960234117664749870297044111962161585341868435055"), stoscalar<T>("0.021172939892191298987673867191003700767616976373645"));
        nodes[43] = std::make_pair<T>(stoscalar<T>("-0.75960234117664749870297044111962161585341868435055"), stoscalar<T>("0.021172939892191298987673867191003700767616976373645"));
        nodes[44] = std::make_pair<T>(stoscalar<T>("0.73803064374440013285116573109649710522971970586168"), stoscalar<T>("0.021966644438744349194756386801562236250168956413498"));
        nodes[45] = std::make_pair<T>(stoscalar<T>("-0.73803064374440013285116573109649710522971970586168"), stoscalar<T>("0.021966644438744349194756386801562236250168956413498"));
        nodes[46] = std::make_pair<T>(stoscalar<T>("0.71567681234896762622514414805762485529757997051247"), stoscalar<T>("0.022737069658329374001347841977490286355700324600827"));
        nodes[47] = std::make_pair<T>(stoscalar<T>("-0.71567681234896762622514414805762485529757997051247"), stoscalar<T>("0.022737069658329374001347841977490286355700324600827"));
        nodes[48] = std::make_pair<T>(stoscalar<T>("0.69256453664217156134424576981824255945409652925886"), stoscalar<T>("0.02348339908592621984223593266761258095476559518221"));
        nodes[49] = std::make_pair<T>(stoscalar<T>("-0.69256453664217156134424576981824255945409652925886"), stoscalar<T>("0.02348339908592621984223593266761258095476559518221"));
        nodes[50] = std::make_pair<T>(stoscalar<T>("0.6687183100439161539525572075727741890244906209117"), stoscalar<T>("0.024204841792364691282267337872677038949832491575032"));
        nodes[51] = std::make_pair<T>(stoscalar<T>("-0.6687183100439161539525572075727741890244906209117"), stoscalar<T>("0.024204841792364691282267337872677038949832491575032"));
        nodes[52] = std::make_pair<T>(stoscalar<T>("0.64416340378496710679841235006330156230309920407587"), stoscalar<T>("0.02490063322248361028838218086833273645367805861244"));
        nodes[53] = std::make_pair<T>(stoscalar<T>("-0.64416340378496710679841235006330156230309920407587"), stoscalar<T>("0.02490063322248361028838218086833273645367805861244"));
        nodes[54] = std::make_pair<T>(stoscalar<T>("0.61892584012546857038636928698786279738592430429414"), stoscalar<T>("0.025570036005349361498797167943600086096340054694224"));
        nodes[55] = std::make_pair<T>(stoscalar<T>("-0.61892584012546857038636928698786279738592430429414"), stoscalar<T>("0.025570036005349361498797167943600086096340054694224"));
        nodes[56] = std::make_pair<T>(stoscalar<T>("0.59303236477757208068355575504375821317360213751037"), stoscalar<T>("0.026212340735672413913457963964463343561605997311238"));
        nodes[57] = std::make_pair<T>(stoscalar<T>("-0.59303236477757208068355575504375821317360213751037"), stoscalar<T>("0.026212340735672413913457963964463343561605997311238"));
        nodes[58] = std::make_pair<T>(stoscalar<T>("0.56651041856139716840425019508346263231068260549435"), stoscalar<T>("0.026826866725591762198056728714156645865322720814034"));
        nodes[59] = std::make_pair<T>(stoscalar<T>("-0.56651041856139716840425019508346263231068260549435"), stoscalar<T>("0.026826866725591762198056728714156645865322720814034"));
        nodes[60] = std::make_pair<T>(stoscalar<T>("0.53938810832435743622680259732556063817453062909571"), stoscalar<T>("0.027412962726029242823421087489091270698572961074541"));
        nodes[61] = std::make_pair<T>(stoscalar<T>("-0.53938810832435743622680259732556063817453062909571"), stoscalar<T>("0.027412962726029242823421087489091270698572961074541"));
        nodes[62] = std::make_pair<T>(stoscalar<T>("0.51169417715466767358550974542885430324944473944896"), stoscalar<T>("0.027970007616848334439818576589022507844891305886778"));
        nodes[63] = std::make_pair<T>(stoscalar<T>("-0.51169417715466767358550974542885430324944473944896"), stoscalar<T>("0.027970007616848334439818576589022507844891305886778"));
        nodes[64] = std::make_pair<T>(stoscalar<T>("0.48345797392059635976840560936389525547125161800448"), stoscalar<T>("0.028497411065085385645599512945805604569697298351756"));
        nodes[65] = std::make_pair<T>(stoscalar<T>("-0.48345797392059635976840560936389525547125161800448"), stoscalar<T>("0.028497411065085385645599512945805604569697298351756"));
        nodes[66] = std::make_pair<T>(stoscalar<T>("0.45470942216774300863567614808630781300400711588389"), stoscalar<T>("0.028994614150555236542678781279681573055015500917621"));
        nodes[67] = std::make_pair<T>(stoscalar<T>("-0.45470942216774300863567614808630781300400711588389"), stoscalar<T>("0.028994614150555236542678781279681573055015500917621"));
        nodes[68] = std::make_pair<T>(stoscalar<T>("0.4254789884073005453648192035699979448147896379862"), stoscalar<T>("0.029461089958167905970436332182858449251622520413431"));
        nodes[69] = std::make_pair<T>(stoscalar<T>("-0.4254789884073005453648192035699979448147896379862"), stoscalar<T>("0.029461089958167905970436332182858449251622520413431"));
        nodes[70] = std::make_pair<T>(stoscalar<T>("0.39579764982890860328500024313516415971218337571042"), stoscalar<T>("0.029896344136328385984388075794400060540161163343384"));
        nodes[71] = std::make_pair<T>(stoscalar<T>("-0.39579764982890860328500024313516415971218337571042"), stoscalar<T>("0.029896344136328385984388075794400060540161163343384"));
        nodes[72] = std::make_pair<T>(stoscalar<T>("0.3656968614723136350308955939954731772311874490388"), stoscalar<T>("0.030299915420827593794088764206500914070317780217681"));
        nodes[73] = std::make_pair<T>(stoscalar<T>("-0.3656968614723136350308955939954731772311874490388"), stoscalar<T>("0.030299915420827593794088764206500914070317780217681"));
        nodes[74] = std::make_pair<T>(stoscalar<T>("0.33520852289262542261632562480562867218708710620202"), stoscalar<T>("0.03067137612366914901422883035620427627242384548287"));
        nodes[75] = std::make_pair<T>(stoscalar<T>("-0.33520852289262542261632562480562867218708710620202"), stoscalar<T>("0.03067137612366914901422883035620427627242384548287"));
        nodes[76] = std::make_pair<T>(stoscalar<T>("0.30436494435449635302392977929520331815117711827684"), stoscalar<T>("0.0310103325863138374232497799706326368443931363825"));
        nodes[77] = std::make_pair<T>(stoscalar<T>("-0.30436494435449635302392977929520331815117711827684"), stoscalar<T>("0.0310103325863138374232497799706326368443931363825"));
        nodes[78] = std::make_pair<T>(stoscalar<T>("0.2731988125910491414872721557245647944481839953937"), stoscalar<T>("0.03131642559686135581278426671506312817571029460685"));
        nodes[79] = std::make_pair<T>(stoscalar<T>("-0.2731988125910491414872721557245647944481839953937"), stoscalar<T>("0.03131642559686135581278426671506312817571029460685"));
        nodes[80] = std::make_pair<T>(stoscalar<T>("0.24174315616384001232793190374062767031155822242391"), stoscalar<T>("0.031589330770727168558020746169964160125034471189385"));
        nodes[81] = std::make_pair<T>(stoscalar<T>("-0.24174315616384001232793190374062767031155822242391"), stoscalar<T>("0.031589330770727168558020746169964160125034471189385"));
        nodes[82] = std::make_pair<T>(stoscalar<T>("0.21003131046056720360284718571229577514423010941407"), stoscalar<T>("0.031828758894411006534753739885532253497890898885611"));
        nodes[83] = std::make_pair<T>(stoscalar<T>("-0.21003131046056720360284718571229577514423010941407"), stoscalar<T>("0.031828758894411006534753739885532253497890898885611"));
        nodes[84] = std::make_pair<T>(stoscalar<T>("0.17809688236761860275940262517649151491438833028585"), stoscalar<T>("0.032034456231992663218138977470211162994503579182409"));
        nodes[85] = std::make_pair<T>(stoscalar<T>("-0.17809688236761860275940262517649151491438833028585"), stoscalar<T>("0.032034456231992663218138977470211162994503579182409"));
        nodes[86] = std::make_pair<T>(stoscalar<T>("0.14597371465489694198910733334332646047430899161478"), stoscalar<T>("0.032206204794030250668667114557232518503917793388139"));
        nodes[87] = std::make_pair<T>(stoscalar<T>("-0.14597371465489694198910733334332646047430899161478"), stoscalar<T>("0.032206204794030250668667114557232518503917793388139"));
        nodes[88] = std::make_pair<T>(stoscalar<T>("0.11369585011066592091120809541432808062547462543047"), stoscalar<T>("0.03234382256857592842877483882894327042810096289997"));
        nodes[89] = std::make_pair<T>(stoscalar<T>("-0.11369585011066592091120809541432808062547462543047"), stoscalar<T>("0.03234382256857592842877483882894327042810096289997"));
        nodes[90] = std::make_pair<T>(stoscalar<T>("0.081297495464425558994471262974752858778294887311665"), stoscalar<T>("0.032447163714064269364012788448845858333373635300547"));
        nodes[91] = std::make_pair<T>(stoscalar<T>("-0.081297495464425558994471262974752858778294887311665"), stoscalar<T>("0.032447163714064269364012788448845858333373635300547"));
        nodes[92] = std::make_pair<T>(stoscalar<T>("0.048812985136049731111958204261275057080951125710578"), stoscalar<T>("0.03251611871386883598720549144777835466900356913349"));
        nodes[93] = std::make_pair<T>(stoscalar<T>("-0.048812985136049731111958204261275057080951125710578"), stoscalar<T>("0.03251611871386883598720549144777835466900356913349"));
        nodes[94] = std::make_pair<T>(stoscalar<T>("0.016276744849602969579134563695238453562045890115892"), stoscalar<T>("0.032550614492363166241961418297285731487308013457197"));
        nodes[95] = std::make_pair<T>(stoscalar<T>("-0.016276744849602969579134563695238453562045890115892"), stoscalar<T>("0.032550614492363166241961418297285731487308013457197"));

        return nodes;
    }


    throw std::runtime_error("Invalid num_nodes passed to gauss_legendre_nodes");
}

}
}

