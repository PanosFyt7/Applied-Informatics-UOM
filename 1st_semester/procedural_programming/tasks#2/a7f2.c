#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main () {
        long kwdikos_a;
        double misthos_e;
        double ebdomadiaia_a;
        int wres_ebdomadiaias_ergasias;
        double amoibh_w;

        printf ("Dwse ton kwdiko:");
        kwdikos_a=GetLong();
        if (kwdikos_a >= 1000) {
            printf ("Dwse ton ethsio mistho:");
            misthos_e=GetReal();
            ebdomadiaia_a=misthos_e/52;
        }
        else {
            printf ("Dwse tis wres ebdomadiaias ergasias:");
            wres_ebdomadiaias_ergasias=GetInteger();
            printf ("Dwse thn amoibh ana wra:");
            amoibh_w=GetReal();
            if  (wres_ebdomadiaias_ergasias<=40) {
                 ebdomadiaia_a=wres_ebdomadiaias_ergasias * amoibh_w;
            }
            else {
                 ebdomadiaia_a=wres_ebdomadiaias_ergasias * amoibh_w + (wres_ebdomadiaias_ergasias - 40)*(amoibh_w*0.5);
            }
        }
        printf ("H ebdomadiaia amoibh einai %g\n", ebdomadiaia_a);

        return 0;
}
