#include <iostream>

using namespace std;

class Province {
    public:
    string rgo_type; float terrain; float output_amnt; float inf_pres; float ar_pres;
    float production = 0;
    
    Province(){}
    Province(string rgo_type1, float terrain1, float output_amnt1, float inf_pres1, float ar_pres1){
        rgo_type = rgo_type1;
        terrain = terrain1;
        output_amnt = output_amnt1;
        inf_pres = inf_pres1;
        ar_pres = ar_pres1;
    }
};
// rgo type, terrain, arbitrary amount, infastructure, arisocrats

// THIS DOES NOT WORK ERROR, LIKELY BECAUSE CREATING OBJS IN LIST NOT ALLOWED OR SOMETHING WRONG
Province prov_holder[] = {
    Province berlin("grain", 1, 1.8, 0.2, 0.02),
    Province hamburg("grain", 1, 1.8, 0.15, 0.02),
    Province leipzig("cattle", 0.9, 1.8, 0.13, 0.01),
    Province salzburg("cattle", 1, 1.8, 0.15, 0.02),
    Province nowhere("fish", 1, 2.2, 0.15, 0.02),
    Province fish_world("fish", 1.2, 2.2, 1, 0.05),
    Province wasteland("coffee", 0.75, 1.5, 0.15, 0.02),
    Province colonial_1("tea", 1.2, 2.2, 0.05, 0.02),
    Province colonial_2("fruit", 0.9, 2.8, 0.4, 0.015)
};