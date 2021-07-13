#include <stdio.h>
#include <stdlib.h>

#define StackLimit 50

typedef struct{
  int price;
  char size;
} shirts;

typedef shirts StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateStack(StackType *Stack);
void TraverseStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);


int main()
{
    StackType itemsStack,tempStack;
    StackElementType AnItem;
    int i,n;
    char size;
    boolean found;


    CreateStack(&itemsStack);
    CreateStack(&tempStack);

    printf("Give number of items ");
    scanf("%d",&n);

    printf("Give the items to store\n");
    for(i=0;i<n;i++)
    {
        printf("Give price ");
        scanf("%d",&AnItem.price);
        printf("Give size ");
        scanf("%s",&AnItem.size);
        Push(&itemsStack,AnItem);
    }


    printf("Items in the box");
    TraverseStack(itemsStack);


    printf("What size do you want? ");
    scanf("%S",&size);
    found=0;
    while(!EmptyStack(itemsStack) && found==0)
        {
            Pop(&itemsStack,&AnItem);
            if (AnItem.size==size)
            {
                found=1;
            }
            else
            {
                Push(&tempStack,AnItem);
            }
        }
        if(found==1)
        {
            printf("Found the size %c\n",size);
        }
        else
        {
            printf("Not Found the size %c\n",size);
        }
        printf("\n");


        printf("Items in the box");
        TraverseStack(itemsStack);
        printf("Items out of the box");
        TraverseStack(tempStack);


         while(!EmptyStack(tempStack))
        {
            Pop(&tempStack,&AnItem);
            Push(&itemsStack,AnItem);
        }


        printf("Items in the box");
        TraverseStack(itemsStack);
        printf("Items out of the box");
        TraverseStack(tempStack);



}


void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%c, %d\n",Stack.Element[i].size,Stack.Element[i].price);
    }
    printf("\n");
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}
