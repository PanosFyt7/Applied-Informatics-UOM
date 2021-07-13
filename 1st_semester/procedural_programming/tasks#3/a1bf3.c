#include <stdio.h>
#include <math.h>
#include "simpio.h"
#include "genlib.h"


int main () {
        long xronia,telikos_arithmos_aytok,Arithmos_Aytok,Orio ;
        double Rythmos;
        printf ("Dwse ton arxiko arithmo aytokinhtwn:");
        Arithmos_Aytok=GetLong();
        printf ("Dwse ton ethsio rythmo ayxhshs:");
        Rythmos=GetReal();
        printf ("Dwse to orio:");
        Orio=GetLong();
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
