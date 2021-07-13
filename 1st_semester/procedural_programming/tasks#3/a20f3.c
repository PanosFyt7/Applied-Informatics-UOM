#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main () {
        int hlikia,max_hlikia,min_hlikia;


        printf ("Dwse hlikia:");
        hlikia=GetInteger();
        if (hlikia!=-1) {
        min_hlikia=hlikia;
        max_hlikia=hlikia;
        while (hlikia!=-1)
        {
            if (hlikia>=max_hlikia)
            {
                max_hlikia=hlikia;
            }
            if (hlikia<min_hlikia)
            {
                min_hlikia=hlikia;
            }
            printf ("Dwse hlikia:");
            hlikia=GetInteger();
        }
        printf ("H megalyterh hlikia einai %d\n",max_hlikia);
        printf ("H mikroterh hlikia einai %d\n",min_hlikia);
        }
}
