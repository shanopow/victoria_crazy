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
