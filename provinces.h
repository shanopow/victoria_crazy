#include <iostream>
using namespace std;

class Province{
    public:
    string rgo_type; float terrain; float output_amnt; float inf_pres; float ar_pres;
    
    Province(){}
    Province(string rgo_type1, float terrain1, float output_amnt1, float inf_pres1, float ar_pres1){
        rgo_type = rgo_type1;
        terrain = terrain1;
        output_amnt = output_amnt1;
        inf_pres = inf_pres1;
        ar_pres = ar_pres1;
    }
    void prov_printer(){
        cout << rgo_type << "\n";
    }

    // calcs base production rate (1 + terrain) * output amount
    float base(float terrain, float output_amnt){
        return ((1 + terrain) * output_amnt);
    }

    // calcs output efficiency (1 + arisocrats% + infrastructure% + terain)
    float output_eff(float terrain, float a_pres, float inf_pres){ 
    return 1 + a_pres + terrain + inf_pres;
    }
    
    // overall holder for rgo formula (base * output efficiency)
    unordered_map<string, float> production(unordered_map<string, float> total_outputs){
        float outputs = base(terrain, output_amnt) * output_eff(terrain, ar_pres, inf_pres);
        if (total_outputs.count(rgo_type) > 0){
            total_outputs[rgo_type] = total_outputs[rgo_type] + outputs;
        } 
        else{
            total_outputs[rgo_type] = outputs;
        }
    return total_outputs;
    }
};

void province_creator(Province prov_holder[]){
    // rgo type, terrain, arbitrary amount, infastructure, arisocrats
    /*
    Province hamburg("grain", 1, 1.8, 0.15, 0.02);
    Province leipzig("cattle", 0.9, 1.8, 0.13, 0.01);
    Province salzburg("cattle", 1, 1.8, 0.15, 0.02);
    Province nowhere("fish", 1, 2.2, 0.15, 0.02);
    Province fish_world("fish", 1.2, 2.2, 1, 0.05);
    Province wasteland("coffee", 0.75, 1.5, 0.15, 0.02);
    Province colonial_1("tea", 1.2, 2.2, 0.05, 0.02);
    Province colonial_2("fruit", 0.9, 2.8, 0.4, 0.015);
    */
    prov_holder[0] = Province("grain", 1, 1.8, 0.15, 0.02);
    prov_holder[1] = Province("cattle", 0.9, 1.8, 0.13, 0.01);
    prov_holder[2] = Province("cattle", 1, 1.8, 0.15, 0.02);
    prov_holder[3] = Province("fish", 1, 2.2, 0.15, 0.02);
    prov_holder[4] = Province("fish", 1.2, 2.2, 1, 0.05);
    prov_holder[5] = Province("coffee", 0.75, 1.5, 0.15, 0.02);
    prov_holder[6] = Province("tea", 1.2, 2.2, 0.05, 0.02);
    prov_holder[7] = Province("fruit", 0.9, 2.8, 0.4, 0.015);
}

// THIS DOES NOT WORK ERROR, LIKELY BECAUSE CREATING OBJS IN LIST NOT ALLOWED OR SOMETHING WRONG
//prov_holder[i] = berlin;
/*
    Province hamburg("grain", 1, 1.8, 0.15, 0.02),
    Province leipzig("cattle", 0.9, 1.8, 0.13, 0.01),
    Province salzburg("cattle", 1, 1.8, 0.15, 0.02),
    Province nowhere("fish", 1, 2.2, 0.15, 0.02),
    Province fish_world("fish", 1.2, 2.2, 1, 0.05),
    Province wasteland("coffee", 0.75, 1.5, 0.15, 0.02),
    Province colonial_1("tea", 1.2, 2.2, 0.05, 0.02),
    Province colonial_2("fruit", 0.9, 2.8, 0.4, 0.015)
*/