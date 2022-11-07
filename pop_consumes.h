string farmer_consumes [3][5][2] = { 
    { {"grain","2.5"},{"fish","1"},{"fruit","1"},{"cattle","0.75"},{"null","0"} },
    { {"tea","4"},{"liquor","3"},{"clothes","1.2"},{"furniture","1.1"},{"null","0"} },
    { {"furniture","3"},{"clothes","3"},{"liquor","1.5"},{"paper","1"},{"coffee","0.45"} } 
    };
string artisan_consumes [3][5][2] = { 
    { {"grain","2.5"},{"fish","1"},{"fruit","1"},{"cattle","0.75"},{"null","0"} },
    { {"tea","5"},{"liquor","5"},{"clothes","5"},{"furniture","4"},{"paper","5"} },
    { {"wine","10"},{"coffee","2"},{"cars","1"},{"fuel", "0.2"},{"null", ""} } 
    };


// calcs the demand for a good in overall market
float demander(string demand_type, string demand_amount, Farmer arr[], int sizearr){
    float tot_demand = 0;
    float rgo_d_amnt = stof(demand_amount);
    for (int i = 0 ; i < sizearr; i++){
        tot_demand += rgo_d_amnt;
    }
    return tot_demand;
}