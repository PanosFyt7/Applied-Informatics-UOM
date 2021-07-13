#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 201       //μέγιστο πλήθος στοιχείων συνόλου

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

boolean isPrime(stoixeio_synolou n);
void createPrimeSet(stoixeio_synolou first,stoixeio_synolou last,typos_synolou synolo);
void displaySet(typos_synolou set,stoixeio_synolou first,stoixeio_synolou last);
boolean Melos(stoixeio_synolou stoixeio,typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);

int main()
{
    int first,last;
    _Bool f;
    stoixeio_synolou AnItem;
    typos_synolou set;

    do
    {
    printf("Dwse first:");
    scanf("%d",&first);
    }while (first < 2 || first >=200);

    do
    {
        printf("Dwse last:");
        scanf("%d",&last);
    }while (last < 2 || last > 200 || last <= first);


    createPrimeSet(first,last,set);
    displaySet(set,first,last);


}




boolean isPrime(stoixeio_synolou n)
{
    stoixeio_synolou i, f = 0;

    for (i = 2; i <= n / 2; ++i) {

        // condition for non-prime
        if (n % i == 0) {
            f = 1;
            break;
        }
    }

    return f;
}

void createPrimeSet(stoixeio_synolou first,stoixeio_synolou last,typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        if(isPrime(i))
        {
            synolo[i] = FALSE;
        }
        else
        {
            Eisagogi(i,synolo);
        }

}



void displaySet(typos_synolou set,stoixeio_synolou first,stoixeio_synolou last)
{
    stoixeio_synolou i;

	for (i=first;i < last;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
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
