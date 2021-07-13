#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 10

typedef struct
{
    int code;
    int priority;
} QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);
void insert_prot(QueueType *Queue, QueueElementType Item);


int main()
{
   QueueType AQueue;
   QueueElementType Item;
   int i,amount;

   CreateQ(&AQueue);
   printf("DWSE TO PLITHOS: ");
   scanf("%d",&amount);

   for(i=0;i<amount;i++)
   {
       printf("DWSE TON KODIKO TOU %dou KOMVOU: ",i+1);
       scanf("%d",&Item.code);
       printf("DWSE TO VATHMO PROTERAIOTITAS TOU %dou KOMVOU: ",i+1);
       scanf("%d",&Item.priority);
       insert_prot(&AQueue,Item);
   }

   printf("----------Priority Queue-------------\n");
   TraverseQ(AQueue);

}

void insert_prot(QueueType *Queue, QueueElementType Item)
{
    boolean flag;
    QueuePointer TempPtr;
    QueuePointer CurrPtr;
    QueuePointer PredPtr;

    TempPtr=(QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data=Item;
    TempPtr->Next=NULL;

    if(EmptyQ(*Queue))
    {
      Queue->Front=TempPtr;
      Queue->Rear=TempPtr;
    }
    else
    {
        PredPtr=Queue->Front;
        CurrPtr=Queue->Front;
        flag=FALSE;

        if(CurrPtr->Data.priority>TempPtr->Data.priority)
        {
            Queue->Front=TempPtr;
            TempPtr->Next=CurrPtr;
        }
        else
        {
            while(flag != TRUE && CurrPtr != NULL)
            {
                if(CurrPtr->Data.priority>TempPtr->Data.priority)
                {
                    PredPtr->Next=TempPtr;
                    TempPtr->Next=CurrPtr;
                    flag=TRUE;
                }
                PredPtr=CurrPtr;
                CurrPtr=CurrPtr->Next;
            }
            if(flag!=TRUE)
            {
                PredPtr->Next=TempPtr;
                Queue->Rear=TempPtr;
            }
        }
    }
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %d\n", CurrPtr->Data.priority,CurrPtr->Data.code);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}
