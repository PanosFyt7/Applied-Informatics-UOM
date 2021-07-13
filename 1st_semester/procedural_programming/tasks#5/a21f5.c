#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>

int main () {
    double matrix[5] , diff[4];
    int i;


    for (i=0;i<5;i++) {
        printf ("Enter number (%d) :",i);
        matrix[i]=GetReal();
    }
    for (i=0;i<4;i++) {
        diff[i]=fabs(matrix[i+1]-matrix[i]);
    }
        printf ("%.2f %.2f %.2f %.2f %.2f\n",matrix[0],matrix[1],matrix[2],matrix[3],matrix[4]);
        printf ("%.2f %.2f %.2f %.2f",diff[0],diff[1],diff[2],diff[3]);
}
