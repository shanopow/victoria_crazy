// calcs base production rate (1 + terrain) * output amount
float base(float terrain, float output_amnt){
    return ((1 + terrain) * output_amnt);
}

// calcs output efficiency (1 + arisocrats% + infrastructure% + terain)
float output_eff(float terrain, float a_pres, float inf_pres){ 
    return 1 + a_pres + terrain + inf_pres;
}

// overall holder for rgo formula (base * output efficiency)
float production(float a_pres, float inf_pres, float terrain, float output_amnt){
    return base(terrain, output_amnt) * output_eff(terrain, a_pres, inf_pres);
}