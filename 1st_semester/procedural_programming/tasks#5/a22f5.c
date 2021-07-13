#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>

long long GetLongLong(void);

int main () {
    int pin[16],i;
    long long number,num,sumnew;
    long long temp;

    printf("Insert card number:");
    number=GetLongLong();
    temp = pow(10,16);
    num=number;
    if (number>=1000000000000000 && number<=9999999999999999) {
        for (i=0;i<16;i++)
        {
         pin[i] = num / (temp/10);
         num = num - pin[i] * (temp/10);
         temp=temp/10;
        }
        if (pin[0]<4 || pin[0]>7)
        {
          printf("%lld is invalid",number);
        }
        else
        {
         sumnew=0;
         for (i=0;i<16;i+=2) {
            pin[i]=pin[i]*2;
            if (pin[i] >= 10)
            {
                pin[i]=pin[i]/10 + pin[i]%10;
            }
         }
         for (i=0;i<16;i++)
         {
             sumnew = sumnew + pin[i];
         }
         if (sumnew % 10 == 0)
         {
                 printf(" %lld is VALID\n",number);
         }
         else
         {
             printf(" %lld is invalid\n",number);
         }
        }
}
else  {
    printf(" %lld is invalid\n",number);
}
 }

long long GetLongLong(void)
{
    string line;
    long long value;
    char termch;

    while (TRUE) {
        line = GetLine();
        switch (sscanf(line, " %lld %c", &value, &termch)) {
          case 1:
            FreeBlock(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }
}



