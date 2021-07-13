#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

# define size 100

int returndata(int pin[size]);
void find_range(int pin[size],int amount,int *min,int *max);

int main ()
{
  int pin[size],amount,min,max;

  amount=returndata(pin);
  find_range(pin,amount,&min,&max);
  printf("The range of values is %d-%d\n",min,max);
  return 0;
}

int returndata(int pin[size])
{
    int timh,amount;

    printf("Enter the elements of the array, one per line.\n Use -1 to signal the end of the list.\n");
    amount=-1;
    printf("? ");
    timh=GetInteger();
    while (timh != -1)
    {
         printf("? ");
         amount=amount+1;
         pin[amount]=timh;
         timh=GetInteger();
    }
    return amount+1;
}

void find_range(int pin[size],int amount,int *min,int *max)
{
    int i;

    *min=pin[0];
    *max=pin[0];
    for (i=1;i<amount;i++)
    {
        if (pin[i]<*min)
        {
            *min=pin[i];
        }
    }
    for(i=1;i<amount;i++)
    {
        if (pin[i]>*max)
        {
            *max=pin[i];
        }
    }
}
