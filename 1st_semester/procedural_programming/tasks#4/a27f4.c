#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

long encode(long N);
bool check(long EN);

int main () {
    long l_limit,u_limit,N,EN;

    printf ("Lower Limit :");
    l_limit=GetLong();
    printf ("Upper Limit :");
    u_limit=GetLong();
    for (N=l_limit;N<=u_limit;N++) {
        EN=encode(N);
        printf ("Code : %ld   Encoding : %ld ",N,EN) ;
        if (check (EN) ) {
            printf ("isValid :yes\n");
        }
        else {
            printf ("isValid :no\n");
        }

    }
}

long encode(long N) {
     long dig,EN ;

     dig=(98 - (N*100)%97) % 97 ;
     EN=(N * 100) + dig ;
     return EN ;
}

bool check(long EN) {
    return ( EN % 97 == 1 ) ;
}
