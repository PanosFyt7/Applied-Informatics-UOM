#include <stdio.h>
#include "simpio.h"
#include "genlib.h"


int main () {
        int co2;
        float telh_k;

        printf ("Dwse gram CO2/khm:");
        co2 = GetInteger();
        if (co2>=0&&co2<=120)
        {
            telh_k= 0.9 * co2;
         }
         else if (co2 <= 140)
              {
                telh_k=1.1 * co2;
              }
              else
              {
                 telh_k=1.7 * co2;
              }
        printf ("To poso plhrwmhs einai : %.1f\n",telh_k);
}
