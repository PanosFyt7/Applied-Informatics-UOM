#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 4

typedef struct{
    int arrival_time;
    int start_time;
    int stay_time;
    int end;
}QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void ReadCustomer(QueueType *WaitingQueue);
QueueType TimesInQueue(QueueType *Queue);
void TraverseQ(char ch[],QueueType Queue);

int main()
{
    int i;
    QueueType WaitingQueue;
    QueueType ServiceQueue;

    CreateQ(&WaitingQueue);
    for(i=1;i<=3;i++)
    {
        printf("Give arrival time,stay time for client %d:",i);
        ReadCustomer(&WaitingQueue);
    }
    TraverseQ("WaitingQueue",WaitingQueue);


    ServiceQueue=TimesInQueue(&WaitingQueue);


    TraverseQ("WaitingQueue",WaitingQueue);
    TraverseQ("ServiceQueue",ServiceQueue);

    return 0;

}

void ReadCustomer(QueueType *WaitingQueue)
{

    QueueElementType tmpCustomer;

    scanf("%d,%d",&tmpCustomer.arrival_time,&tmpCustomer.stay_time);
    tmpCustomer.start_time=-1;
    tmpCustomer.end=-1;
    AddQ(&(*WaitingQueue),tmpCustomer);
}

QueueType TimesInQueue(QueueType *Queue)
{
    int m=0;
    QueueType ServiceQueue;
    int earliestStart =0;
    int currentStart=0;
    int currentEnd=0;
    int i=Queue->Front;


    QueueElementType CurrentCust;


    CreateQ(&ServiceQueue);

    while(!EmptyQ(*Queue))
    {
        RemoveQ(*(&Queue),&CurrentCust);
        if((*Queue).Element[i].arrival_time > currentStart)
        {
            currentStart=(*Queue).Element[i].arrival_time;
        }
        else
        {
            currentStart=(*Queue).Element[i].start_time;
        }
        if(m==0)
        {
        currentEnd=currentStart+(*Queue).Element[i].stay_time;
        }
        else if(m==1)
        {
        currentEnd=currentStart+(*Queue).Element[i-1].stay_time;
        }
        else if(m==2)
        {
        currentEnd=currentStart+(*Queue).Element[i-2].stay_time;
        }
        earliestStart=(*Queue).Element[i].stay_time;
        CurrentCust.start_time=currentStart;
        CurrentCust.end=currentEnd;
        AddQ(&ServiceQueue,CurrentCust);
        i=i+2;
        m++;
    }
    return (ServiceQueue);
}


void TraverseQ(char ch[],QueueType Queue) {
	int current;
	int i=1;
	if(!EmptyQ(Queue))
    {
    printf("%s\n",ch);
	current = Queue.Front;
	printf("Client \t\tStart\tEnd\tArrival\tStay\n");
	while (current != Queue.Rear)
        {
        printf("Client %d \t%d\t%d\t%d\t%d\n",i, Queue.Element[current].start_time,Queue.Element[current].end,Queue.Element[current].arrival_time,Queue.Element[current].stay_time);
		current = (current + 1) % QueueLimit;
		i++;
	    }
    }
	else
    {
        printf("%s is empty",ch);
    }
	printf("\n");
}


void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}
