#include <stdio.h>
 #include "simpio.h"
#include "genlib.h"
#include <math.h>

#define  N  5

void readdata(int x,int atomo[N][4]);
void findmean(int atomo[N][4],int num,double *avg_an,double *avg_gyn);

int main()
{
    int atomo[N][4];
    double avg_b_an,avg_b_gyn,avg_yp_an,avg_yp_gyn,avg_hl_an,avg_hl_gyn;

    readdata(N,atomo);
    findmean(atomo,1,&avg_b_an,&avg_b_gyn);
    printf("\nMesos oros barous andrwn : %.1f\n",avg_b_an);
    printf("Mesos oros barous gynaikwn : %.1f\n",avg_b_gyn);
    findmean(atomo,2,&avg_yp_an,&avg_yp_gyn);
    printf("\nMesos oros ypsous andrwn : %.1f\n",avg_yp_an);
    printf("Mesos oros ypsous gynaikwn : %.1f\n",avg_yp_gyn);
    findmean(atomo,3,&avg_hl_an,&avg_hl_gyn);
    printf("\nMesos oros hlikias andrwn : %.1f\n",avg_hl_an);
    printf("Mesos oros hlikias gynaikwn : %.1f\n",avg_hl_gyn);
}

void readdata(int x,int atomo[N][4])
{
    int i;

    for(i=0;i<x;i++)
     {
       printf("Dwse fylo: ");
       atomo[i][0]=GetInteger();
       printf ("Dwse baros: ");
       atomo[i][1]=GetInteger();
       printf ("Dwse ypsos: ");
       atomo[i][2]=GetInteger();
       printf ("Dwse hlikia: ");
       atomo[i][3]=GetInteger();
       printf("--------\n");
     }
}

void findmean(int atomo[N][4],int num,double *avg_an,double *avg_gyn)
{
    int i,sum_an,sum_gyn,an,gyn;
    sum_gyn=0;
    sum_an=0;
    an=0;
    gyn=0;

    for (i=0;i<N;i++)
    {
        if(atomo[i][0]==0)
        {
            an=an+1;
            sum_an=sum_an+atomo[i][num];
        }
        else if (atomo[i][0]==1)
        {
            gyn=gyn+1;
            sum_gyn=sum_gyn+atomo[i][num];
        }
    }
    *avg_an=(double)sum_an/(double) an;
    *avg_gyn=(double)sum_gyn/(double)gyn;
}
