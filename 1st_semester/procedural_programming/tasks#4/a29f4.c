#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>

int gcd(int a,int b);
bool coprime(int i,int n);
int phi(int n);


int main () {
    int x,i;

    printf ("Enter X:");
    x=GetInteger();
    for (i=1;i<=x;i++) {
        printf("phi(%d) = %d\n",i,phi(i));
    }
}

int gcd(int a,int b) {
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b,a % b);
    }
}

bool coprime(int i,int n) {
    return (gcd(i,n) == 1);
}

int phi(int n) {
    int i,counter;
    counter=0;

    for (i=1;i<=n;i++) {
        if (coprime(i,n))
        {
            counter=counter + 1 ;
        }
    }
    return counter;
}
