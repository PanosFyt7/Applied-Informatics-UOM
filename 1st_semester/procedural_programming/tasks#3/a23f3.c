#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main () {
        int number,i;

        printf ("Enter number:");
        number=GetInteger();
        if (number % 2 ==0)
        {
            for (i=0;i<=number;i=i+2)
            {
                printf ("%d ", i);
            }
        }
        else
        {
            for (i=1;i<=number;i=i+2)
            {
                printf ("%d ", i);
            }
        }

}
