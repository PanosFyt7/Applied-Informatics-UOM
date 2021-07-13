#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

bool Valid_Time (int wra,int min,int sec);


int main () {
    int wra,min,sec;

    printf ("Dwse tis wres :");
    wra=GetInteger();
    printf ("Dwse ta lepta :");
    min=GetInteger();
    printf ("Dwse ta deferolepta :");
    sec=GetInteger();
    if ( Valid_Time(wra,min,sec) ) {
        printf ("WRA EGKYRH");
    }
    else {
        printf ("WRA MH EGKYRH");
    }
}

bool Valid_Time(int wra,int min,int sec) {
     return ( (wra>=0 && wra<=23) ) && (min>=0 && min<=59 && sec>=0 && sec<=59) ;
}
