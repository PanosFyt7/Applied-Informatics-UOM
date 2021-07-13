#include <stdio.h>
#include <stdlib.h>

#define StackLimit 15

typedef int StackElementType;
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
    StackType AStack,tempS;
    StackElementType n,s,x,temp,AnItem;
    int i;

    CreateStack(&AStack);
   for (i=0;i<StackLimit;i++)
   {
        AnItem = i * 10;
        Push(&AStack,AnItem);
   }
   TraverseStack(AStack);
    s=(AStack.Top-1)/2;
    printf("Give nth element (n<=%d) ",s);
    scanf("%d",&n);
    for(i=0;i<2;i++)
        {
            Pop(&AStack,&x);
        }
    printf("\nQuestion a: x=%d",x);
    TraverseStack(AStack);


    Pop(&AStack,&AnItem);
   temp=AnItem;
   Pop(&AStack,&AnItem);
   x=AnItem;
   Push(&AStack,x);
   Push(&AStack,temp);
   printf("\nQuestion b: x=%d",x);
   TraverseStack(AStack);


     for(i=0;i<n;i++)
        {
            Pop(&AStack,&x);
        }
    printf("\nQuestion c: x=%d",x);
    TraverseStack(AStack);

      CreateStack(&tempS);
     for(i=0;i<n;i++)
        {
            Pop(&AStack,&x);
            Push(&tempS,x);
        }
     printf("\nQuestion d: x=%d",x);
     while(!EmptyStack(tempS))
        {
            Pop(&tempS,&x);
            Push(&AStack,x);
        }
    TraverseStack(AStack);


    while(!EmptyStack(AStack))
        {
            Pop(&AStack,&x);
            Push(&tempS,x);
        }
    printf("\nQuestion e: x=%d",x);
    while(!EmptyStack(tempS))
        {
            Pop(&tempS,&x);
            Push(&AStack,x);
        }
     TraverseStack(AStack);

    while(AStack.Top>1)
        {
            Pop(&AStack,&x);
            Push(&tempS,x);
        }
     printf("\nQuestion f: x=%d",x);
    while(!EmptyStack(tempS))
        {
            Pop(&tempS,&x);
            Push(&AStack,x);
        }
    TraverseStack(AStack);


    while(!EmptyStack(AStack))
        {
            Pop(&AStack,&x);
        }
     printf("\nQuestion g: x=%d",x);
     TraverseStack(AStack);

    return 0;
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
        printf("%d ",Stack.Element[i]);
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



