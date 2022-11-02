#include <unordered_map>

class Market {
    public:
    unordered_map<string, float> market_h;
    Market(){
    market_h["p_grain"] = 4;
    market_h["p_fish"] = 4;
    market_h["p_cattle"] = 4;
    market_h["p_tea"] = 5;
    market_h["p_coffee"] = 9;
    market_h["p_clothes"] = 14;
    market_h["p_furniture"] = 17;
    market_h["p_liquor"] = 8;
    market_h["p_paper"] = 5.6;
    market_h["p_car"] = 20;
    market_h["p_fuel"] = 8;    
    }
    market_printer(unordered_map<string, float> market_h){
        for (auto x : market_h)
        cout << x.first << " " << x.second << endl;
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
};

class Artisan {
    public:
    int id;
    int wealth = 100;
    float pop_literacy = 0.1;
    
    Artisan(){}
    Artisan(int id1){
        id = id1;
    }
};
