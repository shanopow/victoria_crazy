#include <iostream>
#include <iterator>
#include <unordered_map>
#include <math.h>
#include <vector>

#include "provinces.h"
#include "classes.h"
#include "pop_consumes.h"
using namespace std;

int main(){
    // market created
    Market m;

    // provinces created
    vector <Province> prov_holder;
    province_creator(prov_holder);
    int prov_size = prov_holder.size();

    // farmers created
    // replace with vector, can dynamically change the size then
    // multiplications of 10 always
    Farmer farmers[100];
    int f_size = sizeof(farmers)/sizeof(*farmers);
    // distribute farmers across each province
    for(int i = 0 ; i < f_size ; i++){
        if (i < (f_size / 2)){
            farmers[i] = Farmer(0);
        }
        if (i <= (f_size / 2)){
            farmers[i] = Farmer(1);
        }
    }

/*
    Artisan artisans[10];
    for(int i = 0; i < 10; i++){
    }
*/
    // calcing global outputs
    unordered_map <string, float> total_outputs;
    for (int i = 0; i < prov_size; i++){
        cout << prov_holder[0].rgo_type << "\n";
        total_outputs = prov_holder[i].production(total_outputs);
    }
    for (auto x : total_outputs){
        cout << x.first << ": " << x.second << "\n";
    }
    
    // demands of pops in state
    cout << "----------------------------------------" << "\n";
    // sims 25 days
    for (int i = 0 ; i < 25 ; i++){
        // checks each rgo that pop consumes one at a time
        for (int i = 0; i < 15; i++){
            float demand = demander(farmer_consumes[0][i][0], farmer_consumes[0][i][1] , farmers, sizeof(farmers)/sizeof(*farmers));
            // to use the attributes for market_h
            string market_change = "p_" + farmer_consumes[0][i][0];
            m = market_updater(m, market_change, total_outputs[farmer_consumes[0][i][0]], demand);
        }
    }
m.market_printer(m.market_h);
return 0;
}