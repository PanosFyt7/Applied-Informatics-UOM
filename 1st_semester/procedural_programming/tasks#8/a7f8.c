
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>


typedef struct {
   int number;
   char type[20];
   int cc;
   char name[20];
   int days;
   float daily_rate;
   float total_charge;
}car_rentalT;

typedef struct{
   int cc;
   char type[20];
   float total_charge;
}best_carT;


int get_data(car_rentalT rentals[]);
float calc_totals(int num_rentals, car_rentalT rentals[]);
best_carT find_best(int num_rentals, car_rentalT rentals[]);
void print_data(int num_rentals, car_rentalT rentals[], best_carT best, float total);

int main ()
{

  car_rentalT rentals[20];
  int number;
  float total;
  best_carT best;


  number = get_data(rentals);


  total = calc_totals(number, rentals);
  best = find_best(number,rentals);


  printf("\n");
  print_data(number,rentals,best,total);

    return 0;
}



int get_data(car_rentalT rentals[])
{
    int num_rentals, i;
    printf("Dwse ton arithmo enoikiasewn: ");
    num_rentals = GetInteger();
    printf("\n");
    for(i=0;i<num_rentals;i++)
    {
      printf("Dwse ta stoixeia tis enoikiasis: %d\n",i);
      rentals[i].number = i;
      printf("Dwse marka: ");
      gets(rentals[i].type);
      printf("Dwse kyvika: ");
      rentals[i].cc = GetInteger();
      printf("Dwse to onoma pelati: ");
      gets(rentals[i].name);
      printf("Dwse imeres enoikiasis: ");
      rentals[i].days = GetInteger();
      printf("Dwse timi ana imera: ");
      rentals[i].daily_rate = GetReal();
      printf("\n");
    }
    return num_rentals;
}

float calc_totals(int num_rentals, car_rentalT rentals[])
{
   int i;
   float total = 0;
   for(i=0;i<num_rentals;i++)
   {
       rentals[i].total_charge = rentals[i].days*rentals[i].daily_rate;
       total+=rentals[i].total_charge;
   }
   return total;
}

best_carT find_best(int num_rentals, car_rentalT rentals[])
{
   int i;
   best_carT best;
   best.total_charge = rentals[0].total_charge;
   best.cc = rentals[0].cc;
   strcpy (best.type,rentals[0].type);
   for (i=1;i<num_rentals;i++)
   {
      if(best.total_charge<rentals[i].total_charge)
      {
          best.total_charge = rentals[i].total_charge;
          best.cc = rentals[i].cc;
          strcpy(best.type,rentals[i].type);
      }
   }
   return best;
}

void print_data(int num_rentals, car_rentalT rentals[], best_carT best, float total)
{
    int i;
    printf("%-7s %-20s %-10s %-5s %-5s %-6s %-8s\n","Number","Name","Type","CC","Days","Price" ,"Total");
    for(i=0;i<73;i++) printf("-");
    printf("\n");
    for(i=0;i<num_rentals;i++)
    {
        printf("%-7d %-20s %-10s %-5d %-5d %-6.2f %-8.2f\n",rentals[i].number,rentals[i].name, rentals[i].type,rentals[i].cc,
               rentals[i].days,rentals[i].daily_rate, rentals[i].total_charge);
    }
    for(i=0;i<73;i++) printf("-");
    printf("\n");
    printf("%58s %-8.2f\n","Total",total);
    printf("Best car: %s %d rented for %.2f Euros.\n",best.type,best.cc,best.total_charge);
}
