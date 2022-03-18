#include "teglalap.h"
#include <math.h>
#include <stdio.h>

void set_Teglalap_data(Teglalap* teglalap, double a, double b, double c){
    teglalap->a = a;
    teglalap->b = b;
    teglalap->c = c;
}

double calc_Teglalap_volume(const Teglalap* teglalap){
    double volume = teglalap->a * teglalap->b * teglalap->c;
    return volume;
}

double calc_Teglalap_surface(const Teglalap* teglalap){
    double surface = 2*(teglalap->a * teglalap->b + teglalap->a * teglalap->c + teglalap->b * teglalap->c);
    return surface;
}

int square_test(const Teglalap* teglalap){
    if(teglalap->a == teglalap->b || teglalap->a == teglalap->c || teglalap->b == teglalap->c){
        return 1;
    }
    else{
        return 0;
    }
}
