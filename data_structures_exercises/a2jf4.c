#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ListLimit 50

typedef int ListElementType;
typedef struct ListNode *ListPointer;
typedef struct ListNode
{
 ListElementType Data;
 ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void insert_list_m_elements(ListPointer *List, int n);


int main()
{
    ListPointer AList,PredPtr;
    ListElementType Item,amount1;
    int i,n;

    PredPtr=NULL;

    CreateList(&AList);

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS :");
	scanf("%d",&amount1);

	for(i=0;i<amount1;i++)
	{   printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS :");
		scanf("%d",&Item);
		LinkedInsert(&AList, Item,  PredPtr);
	}

    printf("*******Arxiki lista*******\n");
    LinkedTraverse(AList);


    printf("DWSE TI THESI, META APO TIN OPOIA THA EISAXTHOUN TA STOIXEIA:");
    scanf("%d",&n);




	insert_list_m_elements(&AList,n);
	printf("*******Teliki lista*******\n");

	LinkedTraverse(AList);


}



void CreateList(ListPointer *List)


{
	*List = NULL;
}

boolean EmptyList(ListPointer List)

{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)

{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));

   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)

{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)

{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
   	 //   printf("%p\n",CurrPtr);
         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
        printf("\n");
   }
}


void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)

{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)

{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}

void insert_list_m_elements(ListPointer *List, int n)
{
	ListPointer TempPtr;
	int i,j,m,item;

	if(EmptyList(*List))
	{
	  printf("EMPTY LIST");
	}
	else
	{
		TempPtr=*List;
		i=1;


		while((TempPtr->Next!=NULL) && (i<n))
		{
		   TempPtr=TempPtr->Next;
		   i++;
		}

		if(i<n || i<1)
		{
		printf("ERROR\n");
		}
		else
		{
			printf("DWSE TO PLITHOS TWN STOIXEIWN POY THA EISAXTHOYN: ");
			scanf("%d",&m);

			for(i=0; i<m; i++){
				printf("DWSE TON ARITHMO GIA EISAGWGH STH LISTA: ");
				scanf("%d",&item);
				LinkedInsert(List,item,TempPtr);
				TempPtr=TempPtr->Next;
			}
		}
	}
}

