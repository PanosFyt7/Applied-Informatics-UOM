#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main () {
         int kafedes,resta,kermata_2,ypol_2,kermata_1,ypol_1,kermata_50,ypol_50,kermata_20,ypol_20,kermata_10,ypol_10;


         printf ("Dwse kafedes :");
         kafedes=GetInteger();
         if (kafedes*70 <= 500) {
            printf ("Resta \n");
            resta=500-kafedes*70;
            kermata_2=resta/200;
            printf("Kermata 2E : %d\n",kermata_2);
            ypol_2=resta%200;
            kermata_1=ypol_2/100;
            printf("Kermata 1E : %d\n",kermata_1);
            ypol_1=ypol_2%100;
            kermata_50=ypol_1/50;
            printf("Kermata 50L : %d\n",kermata_50);
            ypol_50=ypol_1%50;
            kermata_20=ypol_50/20;
            printf("Kermata 20L : %d\n",kermata_20);
            ypol_20=ypol_50%20;
            kermata_10=ypol_20/10;
            printf("Kermata 10L : %d\n",kermata_10);
            ypol_10=ypol_20%10;
         }
         else {
            printf ("Den ftanoun ta xrhmata gia tosous kafedes");
         }

}

