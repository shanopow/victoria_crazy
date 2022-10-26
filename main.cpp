#include <iostream>
#include <iterator>

#include "production_calc.h"
#include "provinces.h"
#include "pop_province_classes.h"
using namespace std;

//pop demand and supply
float demander(string demand_type, string demand_amount, Farmer arr[], int sizearr);

int main(){
    // market created
    Market m;
    //what each pop consumes
    // move to header file later
    string farmer_consumes [3][5][2] = { 
    { {"grain","0.75"},{"fish","1"},{"fruit","1"},{"cattle","0.75"},{"null","0"} },
    { {"tea","4"},{"liquor","3"},{"clothes","1.2"},{"furniture","1.1"},{"null","0"} },
    { {"furniture","3"},{"clothes","3"},{"liquor","1.5"},{"paper","1"},{"coffee","0.45"} } 
    };

    // farmers in state
    // replace with vector, can dynamically change the size then
    Farmer farmers[100];
    for(int i = 0; i < 100; i++){
        farmers[i] = Farmer(i);
    }
    
    // setting provinces initially
   /* for (int i = 0; i < 9; i++){
        prov_holder[i].production = production(prov_holder[i].ar_pres, prov_holder[i].inf_pres, prov_holder[i].terrain, prov_holder[i].output_amnt); 
        cout << prov_holder[i].production << "\n";
    }
    */

    // demands of pops in state
    float demand;
    for (int i = 0; i < 12; i++){
        demand = demander(farmer_consumes[0][i][0], farmer_consumes[0][i][1] , farmers, sizeof(farmers)/sizeof(*farmers));
        
        //more supply than demand // replace with big old checker aginst all provinces
        if (demand < berlin.production){
            m.p_grain -= 0.01; 
        }
        else{
            m.p_grain += 0.01;
        }
    }
    return 0;
}


// calcs the demand in a province for certain good
float demander(string demand_type, string demand_amount, Farmer arr[], int sizearr){
    float tot_demand = 0;
    float rgo_d_amnt = stof(demand_amount);
    for (int i = 0 ; i < sizearr; i++){
        tot_demand += rgo_d_amnt;
    }
    cout << demand_type << " " << tot_demand << "\n";
    return tot_demand;
}