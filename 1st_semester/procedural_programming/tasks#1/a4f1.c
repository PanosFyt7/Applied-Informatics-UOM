#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {
    double profit,saleAmount;
    long purchaseAmount;
    int rate;

    printf ("Dwse thn katharh axia :");
    purchaseAmount = GetLong ();
    printf ("Dwse to pososto kerdous:");
    rate = GetInteger();
    profit = (rate / 100.0) * purchaseAmount ;
    printf ("To kerdos einai %g\n ",profit);
    saleAmount = purchaseAmount + profit ;
    printf ("To synoliko poso einai %g\n",saleAmount);
    return 0;
}
