#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>

#define SALESMEN 4
#define PRODUCTS 5

void calculatesales(int S,int P,int salestable[S][P],int price[],int sp[]);
void calculateproductsales(int S,int P,int salestable[S][P],int prods[]);
void maxarray(int size,int table[],int *max,int *pos);
void printarray(int size,int table[]);

int main()
{
  int sales[SALESMEN][PRODUCTS] = {
      {10,4,5,6,7},
      {7,0,12,1,3},
      {4,19,5,0,8},
      {3,2,1,5,6}};
  int salesperson[SALESMEN],price[]={250,150,320,210,920},productsale[PRODUCTS];
  int income,maxsalesman,items,productmax;

      calculatesales(SALESMEN,PRODUCTS,sales,price,salesperson);
      calculateproductsales(SALESMEN,PRODUCTS,sales,productsale);
      maxarray(SALESMEN,salesperson,&income,&maxsalesman);
      maxarray(PRODUCTS,productsale,&items,&productmax);
      printf("Salesman-sales\n");
      printarray(SALESMEN,salesperson);
      printf("Best salesman was %d with %d sales\n",maxsalesman,income);
      printf("Products-items\n");
      printarray(PRODUCTS,productsale);
      printf("Best product was %d with %d items\n",productmax,items);
      return 0;
}

void calculatesales(int S,int P,int salestable[S][P],int price[],int sp[])
{
    int i,j;

    for(i=0;i<S;i++)
    {
        sp[i]=0;
        for(j=0;j<P;j++)
        {
            sp[i]+=salestable[i][j] * price[j];
        }
    }
}

void calculateproductsales(int S,int P,int salestable[S][P],int prods[])
{
    int i,j;
    for(i=0;i<P;i++)
    {
        prods[i]=0;
        for(j=0;j<S;j++)
        {
            prods[i]+=salestable[j][i];
        }
    }
}

void maxarray(int size,int table[],int *max,int *pos)
{
    int i;

    *max=table[0];
    *pos=0;
    for(i=1;i<size;i++)
    {
        if(*max<table[i])
        {
            *max=table[i];
            *pos=i;
        }
    }
}

void printarray(int size,int table[])
{
    int i;
    for(i=0;i<size;i++)
    {
        printf(" %d   %d\n",i,table[i]);
    }
}
