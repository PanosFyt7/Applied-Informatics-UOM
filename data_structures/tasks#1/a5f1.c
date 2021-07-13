#include <stdio.h>
#include <stdlib.h>

#define megisto_plithos 1001

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];

typedef int stoixeio_synolou;

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void createFibonacciSet(stoixeio_synolou threshold,typos_synolou synolo);
void displayset(typos_synolou set,stoixeio_synolou max);

boolean isFibonacci(stoixeio_synolou n,typos_synolou synolo)
{
 if(Melos(n,synolo)){
       return TRUE;
     }
 else {
       return FALSE;
      }
}

int main()
{
 stoixeio_synolou max;
 stoixeio_synolou temp;
 typos_synolou Fibonacci;
 printf("Dwse to megistoarithmo.");
 scanf("%d",&max);
 if(max<2 || max>1000)
    {
      printf("Dwse to megistoarithmo.");
      scanf("%d",&max);
    }
 createFibonacciSet(max,Fibonacci);
 displayset(Fibonacci,max);
 while(1)
 {
    printf("Enter number to check:");
    scanf("%d",&temp);
    if(temp<0)
    {
        break;
    }
   if(temp>=0 || temp<=1000){
    if(isFibonacci(temp,Fibonacci)){
        printf("%s\n","Fibonacci!");
    }
    else {
        printf("%s\n","Not Fibonacci...");
    }
}
else{
     printf("Enter number to check:");
    scanf("%d",&temp);
    }
}
        return 0;
        system("PAUSE");
}

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void displayset(typos_synolou set,stoixeio_synolou max)
{
	stoixeio_synolou i;

	for (i=0;i < max;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}



void createFibonacciSet(stoixeio_synolou threshold,typos_synolou synolo)
{
  Dimiourgia(synolo);
  stoixeio_synolou f1,f2,temp;
     f1=0;
     Eisagogi(f1,synolo);
     f2=1;
     for(stoixeio_synolou k=2;k<=threshold;k++){
     Eisagogi(f2,synolo);
     temp=f1+f2;
     if(temp>threshold)
     {
        break;
     }
     f1=f2;
     f2=temp; }
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}


boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}



