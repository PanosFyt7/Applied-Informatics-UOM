#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

typedef struct{
   char name[60];
   int start_month;
   int duration;
}diary;

void ReadWorkPackages(int wp,diary packages[]);
int FindFirstWp(int wp,diary packages[]);
int FindMakespan(int wp,diary packages[]);

int main ()
{
   int wp,prwth,total;
   diary packages[100];

   printf("Total work packages:");
   wp=GetInteger();
   ReadWorkPackages(wp,packages);
   prwth = FindFirstWp(wp,packages);

   printf("FIRST WP: %s start: %d duration: %d\n",packages[prwth].name,packages[prwth].start_month,packages[prwth].duration);
   total=FindMakespan(wp,packages);
   printf("Total Duration = %d\n",total);
}

void ReadWorkPackages(int wp,diary packages[])
{
    int i;

    for (i=0;i<wp;i++)
    {
    printf("WP Name: ");
    gets(packages[i].name);
    printf("WP Start Month: ");
    packages[i].start_month = GetInteger();
    printf("WP Duration: ");
    packages[i].duration = GetInteger();
    }
}

int FindFirstWp(int wp,diary packages[])
{
    int i,min,min_thesi;

    min=packages[0].start_month;
    min_thesi=0;
    for(i=1;i<wp;i++)
    {
       if(packages[i].start_month < min)
       {
           min = packages[i].start_month;
           min_thesi=i;
       }
    }
    return min_thesi;
}

int FindMakespan(int wp,diary packages[])
{
   int i,max,max_thesi;

   max=packages[0].duration;
   for(i=1;i<wp;i++)
   {
       if(packages[i].duration>max)
       {
           max=packages[i].duration;
           max_thesi=i;
       }
   }
   return packages[max_thesi].start_month + packages[max_thesi].duration;
}
