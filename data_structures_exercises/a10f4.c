#include <stdio.h>
#include <stdlib.h>

#define Stacklimit 50


typedef int StackElementType;

typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void TraverseStack(StackPointer Stack);
void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

int main()
{
   int amount,i;
   StackPointer AStack1,AStack2;
   StackElementType item;

   CreateStack(&AStack1);

   printf("PLITHOS STOIXEIWN: ");
   scanf("%d",&amount);

   for(i=0;i<amount;i++)
   {
       printf("DWSE TO %do STOIXEIO: ",i+1);
       scanf("%d",&item);
       Push(&AStack1,item);
   }

   printf("*********1i stoiva***********\n");
   TraverseStack(AStack1);

   CreateStack(&AStack2);

   while(!EmptyStack(AStack1))
   {
       Pop(&AStack1,&item);
       Push(&AStack2,item);
   }

   printf("*********2i stoiva***********\n");
   TraverseStack(AStack2);

   return 0;
}


void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void CreateStack(StackPointer *Stack)
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
