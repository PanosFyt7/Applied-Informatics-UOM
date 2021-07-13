#include <stdio.h>
#include <math.h>
#include "simpio.h"
#include "genlib.h"

#define Arithmos_Aytok 80000
#define Rythmos        0.07
#define Orio           160000

int main () {
        long xronia,telikos_arithmos_aytok ;

        xronia=0;
        telikos_arithmos_aytok=Arithmos_Aytok;
        while (telikos_arithmos_aytok<=Orio)
        {
            xronia=xronia+1;
            telikos_arithmos_aytok= ceil(telikos_arithmos_aytok*(1+Rythmos));
        }
        printf ("%ld\n",xronia);
        printf ("%ld\n",telikos_arithmos_aytok);
}
