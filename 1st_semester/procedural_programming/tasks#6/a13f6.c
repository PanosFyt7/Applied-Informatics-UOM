#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>

void decompose(long number,int *digits,float *average,int *max);

int main()
{
   long number;
   int digits,max;
   float average;

   printf("Please insert non-negative number:");
   number=GetLong();
   decompose(number,&digits,&average,&max);
   printf("Digits: %d\n",digits);
   printf("Average: %.3f\n",average);
   printf("Max: %d\n",max);
   return 0;
}

void decompose(long number,int *digits,float *average,int *max)
{
    float sum;
    int arithmos[*digits],i,dig;

    if (number<10)
    {
        *digits=1;
    }
    else if (number<100)
    {
        *digits=2;
    }
    else if (number<1000)
    {
        *digits=3;
    }
     else if (number<10000)
    {
        *digits=4;
    }
     else if (number<100000)
    {
        *digits=5;
    }
     else if (number<1000000)
    {
        *digits=6;
    }
     else if (number<10000000)
    {
        *digits=7;
    }
     else if (number<100000000)
    {
        *digits=8;
    }
     else if (number<1000000000)
    {
        *digits=9;
    }
     else
    {
        *digits=10;
    }
    dig=*digits;
    for(i=0;i<*digits;i++)
    {
        arithmos[i]=(number/ (pow(10,dig-1)));
        number=(number)%(long)(pow(10,dig-1));
        dig=dig-1;
    }
    for(i=0;i<*digits;i++)
    {
        sum=sum+arithmos[i];
    }
    *average=sum /(float) *digits;
    *max=arithmos[0];
    for(i=1;i<*digits;i++)
    {
        if (arithmos[i] > *max)
        {
            *max=arithmos[i];
        }
    }
}
