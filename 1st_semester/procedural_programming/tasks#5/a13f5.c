#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define D 10

void populate_data(int r,int c,int A[D][D]);
void print_array(int r,int c,int A[D][D]);
void change_array(int r,int c,int A[D][D]);

int main ()
{
   int r,c,i,j;
   int A[D][D];


   printf("Dwse ton arithmo twn grammwn:");
   r=GetInteger();
   printf("Dwse ton arithmo twn sthlwn:");
   c=GetInteger();
   populate_data(r,c,A);
   print_array(r,c,A);
   change_array(r,c,A);
   printf("ALLAGMENOS PINAKAS\n");
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++){
      if (j == c-1)
            {
            printf(" %d \n",A[i][j]);
            }
            else
            {
                printf(" %d ",A[i][j]);
            }
       }
   }
}

void populate_data(int r,int c,int A[D][D])
{
    int i,j;

    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            A[i][j]=rand() % 100;
        }
    }
}

void print_array(int r,int c,int A[D][D])
{
     int i,j;

     printf("ARXIKOS PINAKAS \n");
     for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            if (j == c-1)
            {
            printf(" %d \n",A[i][j]);
            }
            else
            {
                printf(" %d ",A[i][j]);
            }
        }
    }
}

void change_array(int r,int c,int A[D][D])
{
    int i,j,max[D],pos;

    for (i=0;i<r;i++)
    {
        max[i]=A[i][0];
        for(j=1;j<c;j++)
        {
            if (A[i][j]>max[i])
            {
                max[i]=A[i][j];
                pos=j;
            }
        }
        for (j=0;j<pos;j++)
        {
            A[i][j]=max[i];
        }
    }
}

