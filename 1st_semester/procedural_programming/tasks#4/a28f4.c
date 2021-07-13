#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>

int getcode();
double discount_percentage(int code);
int product_points(int code,double price);

int main () {
    int code,points;
    double price,discountsum,total,finalprice,discount;

    total=0;
    discountsum=0;
    points=0;

    while (TRUE) {
        code=getcode() ;
        if (code==0) break;
        printf ("Dwse thn timh :");
        price=GetReal();
        discount=discount_percentage(code)*price;
        discountsum+=discount;
        finalprice=price - discount;
        total+=finalprice;
        points+=product_points(code,finalprice);
    }
    printf("----------------\n");
    printf("Teliko synolo: %.2f Euro\n",total);
    printf("Ekptwsh: %.2f Euro\n", discountsum);
    printf("Pontoi: %d\n", points);
    system ("pause");
    return 0;

}

int getcode() {
    int code;
    while(TRUE) {
          printf ("Dwse ton kwdiko:");
          code = GetInteger();
          if (code>=0 && code<=2000)
            return code;
        printf ("Lathos kwdikos (0-2000)\n");
    }
}

double discount_percentage(int code) {
       if (code>=1 && code<=300)
          return 0.05;
       else if (code<=500)
           return 0.1;
       else if (code<=1000)
           return 0.15;
       else
        return 0.2;
}

int product_points(int code,double finalprice) {
           int points = 1;
           if (code>=1000 && code<=1500)
                points +=ceil(finalprice/5);
           return points;
}
