#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>

int main () {
    int A[5] , B[5];
    int i;

    for (i=0;i<5;i++) {
        printf ("Enter number :");
        A[i]= GetInteger();
        B[i]=A[i];
    }
        for (i=0;i<5;i++) {
            if (i==0)  {
                A[i]=B[4];
            }
            else if (i==1) {
                A[i]=B[0];
            }
            else {
                A[i]=B[i-1];
            }

        }

    printf ("%d  %d  %d  %d  %d",A[0],A[1],A[2],A[3],A[4]);
    return 0;

}
