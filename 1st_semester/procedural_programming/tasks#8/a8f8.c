#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

typedef struct {
     int width;
     int height;
     int depth;
     int area;
     int volume;
}box;

void get_data(box diastasis[]);
void synol_embado(box diastasis[]);
void ypol_vol(box diastasis[]);


int main()
{
   box diastasis[5];

   get_data(diastasis);
   synol_embado(diastasis);
   ypol_vol(diastasis);

   return 0;
}

void get_data(box diastasis[])
{


    printf("Dose to mikos tou koutiou se cm: ");
    diastasis[0].width = GetInteger();
    printf("Dose to ypsos tou koutiou se cm: ");
    diastasis[1].height = GetInteger();
    printf("Dose to vathos tou koutiou se cm: ");
    diastasis[2].depth = GetInteger();
}

void synol_embado(box diastasis[])
{
    diastasis[3].area = 2*(diastasis[0].width * diastasis[2].depth + diastasis[0].width * diastasis[1].height + diastasis[2].depth * diastasis[1].height);
    printf("To emvadon tou koutiou einai %d cm2\n",diastasis[3].area);
}

void ypol_vol(box diastasis[])
{
    diastasis[4].volume = diastasis[0].width * diastasis[1].height * diastasis[2].depth;
    printf("O ogos tou koutiou einai %d cm3\n",diastasis[4].volume);
}
