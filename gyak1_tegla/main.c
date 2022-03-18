#include "teglalap.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    Teglalap teglalap;
    double volume;
    double surface;
    int test;

    set_Teglalap_data(&teglalap, 5,7,6);
    volume = calc_Teglalap_volume(&teglalap);
    surface = calc_Teglalap_surface(&teglalap);

    printf("Teglalap volume: %lf\n", volume);
    printf("Teglalap surface: %lf\n", surface);

    test = square_test(&teglalap);

    if(test == 1)
    {
        printf("Van negyzet alaku lapja");
    }
    else{
        printf("Nincs negyzet alaku lapja");
    }
    return 0;
}
