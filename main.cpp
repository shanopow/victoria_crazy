#include <iostream>
#include <iterator>
using namespace std;

class Market {
    public:
    float p_grain; float p_fish; float p_fruit; float p_cattle; 
    float p_tea; float p_coffee; float p_clothes; float p_furniture;
    float p_liquor; float p_paper; float p_car; float p_fuel;
    Market(){
    p_grain = 3;
    p_fish = 4;
    p_fruit = 4;
    p_cattle = 4;
    p_tea = 5;
    p_coffee = 9;
    p_clothes = 14;
    p_furniture = 17;
    p_liquor = 8;
    p_paper = 5.6;
    p_car = 20;
    p_fuel = 8;
    }
};

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


class Farmer {
    public:
    int id;
    int wealth = 100;
    float pop_literacy = 0.05;

    Farmer(){}
    Farmer(int id1){
        id = id1;
    }
    
    void printer(){
        printf("ID: %i Wealth: %i Literacy: %f\n", id, wealth, pop_literacy);
    }

};

// rgo
float production(float a_pres, float inf_pres ,float terrain, float output_amnt);
float base(float terrain, float output_amnt);
float output_eff(float terrain, float a_pres, float inf_pres);

//pop demand and supply
float demander(string demand_type, string demand_amount, Farmer arr[], int sizearr);
float supplier();

int main(){
    // market created
    Market m;
    //what each pop consumes
    // move to header file
    string farmer_consumes [3][5][2] = { 
    { {"grain","0.75"},{"fish","1"},{"fruit","1"},{"cattle","0.75"},{"null","0"} },
    { {"tea","4"},{"liquor","3"},{"clothes","1.2"},{"furniture","1.1"},{"null","0"} },
    { {"furniture","3"},{"clothes","3"},{"liquor","1.5"},{"paper","1"},{"coffee","0.45"} } 
    };

    // farmers in state
    // linked list maybe
    Farmer farmers[100];
    for(int i = 0; i < 100; i++){
        farmers[i] = Farmer(i);
    }
    
    // rgo calc
    Province berlin("grain", 1, 1.8, 0.2, 0.02);
    berlin.production = production(berlin.ar_pres, berlin.inf_pres, berlin.terrain, berlin.output_amnt);

    // demands of pops in state
    int sizer = (sizeof(farmers)/sizeof(*farmers));
    float demand;
    for (int i = 0; i < 12; i++){
        demand = demander(farmer_consumes[0][i][0], farmer_consumes[0][i][1] , farmers, sizer);
        //more supply than demand
        if (demand < berlin.production){
            m.p_grain -= 0.01; 
        }
        else{
            m.p_grain += 0.01;
        }
    }
    cout << m.p_grain;
    return 0;
}

// overall holder for rgo formula (base * output efficiency)
float production(float a_pres, float inf_pres, float terrain, float output_amnt){
    return base(terrain, output_amnt) * output_eff(terrain, a_pres, inf_pres);
}

// calcs base production rate (1 + terrain) * output amount
float base(float terrain, float output_amnt){
    return ((1 + terrain) * output_amnt);
}

// calcs output efficiency (1 + arisocrats% + infrastructure% + terain)
float output_eff(float terrain, float a_pres, float inf_pres){ 
    return 1 + a_pres + terrain + inf_pres;
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