#ifndef TEGLALAP_H
#define TEGLALAP_H

typedef struct Teglalap{
    double a;
    double b;
    double c;
}Teglalap;

void set_Teglalap_data(Teglalap* teglalap, double a, double b, double c);

double calc_Teglalap_volume(const Teglalap* teglalap);

double calc_Teglalap_surface(const Teglalap* teglalap);

int square_test(const Teglalap* teglalap);

#endif