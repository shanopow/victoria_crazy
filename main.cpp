#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Province{
    public:
    float terrain;
    float output_amnt;
    float inf_pres;
    float ar_pres;
    Province(float terrain1, float output_amnt1, float inf_pres1, float ar_pres1){
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

float production(float a_pres, float inf_pres ,float terrain, float output_amnt);
float base(float terrain, float output_amnt);
float output_eff(float terrain, float a_pres, float inf_pres);

int main(){
    //what each pop consumes
    string farmer_consumes [3][5][2] = { 
    { {"grain","0.75"},{"fish","1"},{"fruit","1"},{"cattle","0.75"},{"null","0"} },
    { {"tea","4"},{"liquor","3"},{"clothes","1.2"},{"furniture","1.1"},{"null","0"} },
    { {"furniture","3"},{"clothes","3"},{"liquor","1.5"},{"paper","1"},{"coffee","0.45"} } 
    };

    // farmer holders
    Farmer farmers[100];
    for(int i = 0; i < 100; i++){
        farmers[i] = Farmer(i);
        farmers[i].printer();
    }
    printf("Welcome to the province of Berlin in Brandenburg\n");
    printf("This PLAINS area produces GRAIN\n");
    // rgo calc
    Province berlin(1, 1.8, 0.2, 0.02);    
    float total = production(berlin.ar_pres, berlin.inf_pres, berlin.terrain, berlin.output_amnt);
    cout << total;
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