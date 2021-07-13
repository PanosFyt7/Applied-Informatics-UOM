#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"
#include <stdlib.h>

void populate(int a[50]);
void printArr(int a[50],int m);
void checkTable(int a[50],int N,int theseis[10],int pin[10]);

int main ()
{
    int a[50],N,theseis[10],m,pin[10];

    m=1;
    populate(a);
    printArr(a,m);
    printf("Dwse arithmo apo to 0 ews to 9 :");
    N=GetInteger();
    checkTable(a,N,theseis,pin);
    printf("\n" "o Arithmos %d emfanizetai %d fores.\n",N,theseis[N]);
    printf("Stis theseis:\n");
    m=2;
    printArr(pin,m);
}

void populate(int a[50])
{
    int i;

    for (i=0;i<50;i++)
    {
        a[i]=rand() % 10;
    }
}

void printArr(int a[50],int m)
{
    int i;

    if(m==1)
    {
    for (i=0;i<50;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n---------------\n");
    }
    if(m==2)
    {
        for (i=0;i<10;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n---------------\n");
    }
}


void checkTable(int a[50],int N,int theseis[10],int pin[10])
{
    int i,j,m;

    for(i=0;i<10;i++)
    {
        theseis[i]=0;
        pin[i]=0;
    }
    for(j=0;j<10;j++)
    {
    for(i=0;i<50;i++)
    {
        if (a[i] == j)
        {
            theseis[j]=theseis[j]+1;
        }
    }
    }
     m=0;
     for (j=0;j<50;j++)
     {
        if (a[j]==N)
        {
            pin[m]=j;
            m=m+1;
        }
     }
}


