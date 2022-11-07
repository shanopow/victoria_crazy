#include <iostream>
using namespace std;

class Province{
    public:
    string rgo_type; float terrain; float output_amnt; float inf_pres; float ar_pres; int id;
    
    Province(){}
    Province(int id1, string rgo_type1, float terrain1, float output_amnt1, float inf_pres1, float ar_pres1){
        id = id1;
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
    total_outputs[rgo_type] = roundf(total_outputs[rgo_type] * 100) / 100;
    return total_outputs;
    }
};

void province_creator(Province prov_holder[]){
    // rgo type, terrain, arbitrary amount, infastructure, arisocrats
    prov_holder[0] = Province(0, "grain", 1, 1.8, 0.15, 0.02);
    prov_holder[1] = Province(1, "cattle", 0.9, 1.8, 0.13, 0.01);
    prov_holder[2] = Province(2, "cattle", 1, 1.8, 0.15, 0.02);
    prov_holder[3] = Province(3, "fish", 1, 2.2, 0.15, 0.02);
    prov_holder[4] = Province(4, "fish", 1.2, 2.2, 1, 0.05);
    prov_holder[5] = Province(5, "coffee", 0.75, 1.5, 0.15, 0.02);
    prov_holder[6] = Province(6, "tea", 1.2, 2.2, 0.05, 0.02);
    prov_holder[7] = Province(7, "fruit", 0.9, 2.8, 0.4, 0.015);
}