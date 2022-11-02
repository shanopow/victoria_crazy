#include <iostream>
#include <iterator>
#include <unordered_map>

#include "provinces.h"
#include "classes.h"
#include "pop_consumes.h"
using namespace std;

//pop demand
float demander(string demand_type, string demand_amount, Farmer arr[], int sizearr);

int main(){
    // market created
    Market m;
    //m.market_printer(m.market_h);

    // provinces created
    Province prov_holder[10];
    province_creator(prov_holder);

    // farmers created
    // replace with vector, can dynamically change the size then
    Farmer farmers[100];
    for(int i = 0; i < 100; i++){
        farmers[i] = Farmer(i);
    }

    // calcing global outputs
    unordered_map <string, float> total_outputs;
    for (int i = 0; i < 8; i++){
        total_outputs = prov_holder[i].production(total_outputs);
    }
    for (auto x : total_outputs){
        cout << x.first << " " << x.second << "\n";
    }
    
    // demands of pops in state
    cout << "----------------------------------------" << "\n";
    for (int i = 0 ; i < 25 ; i++){
    for (int i = 0; i < 12; i++){
        float demand = demander(farmer_consumes[0][i][0], farmer_consumes[0][i][1] , farmers, sizeof(farmers)/sizeof(*farmers));
        cout << farmer_consumes[0][i][0] << " " << demand << "\n";
        // to use the attributes for market_h
        string market_change = "p_" + farmer_consumes[0][i][0];
        // compare supply, demand
        if (demand < total_outputs[farmer_consumes[0][i][0]]){
            m.market_h[market_change] -= 0.01; 
        }
        else{
            m.market_h[market_change] += 0.01;
        }
    }
    }
    cout << "----------------------------------------" << "\n";
    m.market_printer(m.market_h);
return 0;
}
// end of main

// calcs the demand in a province for certain good
float demander(string demand_type, string demand_amount, Farmer arr[], int sizearr){
    float tot_demand = 0;
    float rgo_d_amnt = stof(demand_amount);
    for (int i = 0 ; i < sizearr; i++){
        tot_demand += rgo_d_amnt;
    }
    return tot_demand;
}