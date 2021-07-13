#include <stdio.h>
#include "string.h"

int main ()
{
    char ch[100];
    _Bool f;
    int i,time,sum;

    time=1;
    f=0;
    sum=0;
    printf("Insert a string: ");
    gets(ch);
    for(i=0;i<99;i++)
    {
        if(ch[i]>= '0' && ch[i]<= '9')
        {
            f=1;
            if(time==1)
            {
            printf("%c ",ch[i]);
            }
            else if (time>1)
            {
                printf("+ %c ",ch[i]);
            }
            time=time + 1;
            sum=sum + (ch[i]-'0');
        }
    }
    if(f==0)
    {
        printf("No digits in input.\n");
    }
    else if (f==1)
    {
        printf("= %d\n",sum);
    }
    return 0;
}
