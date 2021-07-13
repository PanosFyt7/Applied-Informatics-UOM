#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main () {
         int N,i;
         float sum;

         printf ("Dwse orio:");
         N=GetInteger();
         sum=0;
         for (i=1;i<=N;i++)
         {
             sum=sum + 1/(float)i;
         }
         printf ("To athroisma einai %.2f\n",sum);

}
