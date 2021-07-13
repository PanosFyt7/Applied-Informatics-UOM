#include <stdio.h>
#include <stdlib.h>


#define QueueLimit 10

typedef int QueueElementType;   /* � ����� ��������� ��� ��������� ��� �����
                                  ���������� ����� int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int Count;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);


int main()
{
   QueueType AQueue;

   int i;
   QueueElementType AnItem;

  CreateQ(&AQueue);

  printf("---a---\n");
  for(i=0;i<10;i++)
  {
     AddQ(&AQueue,i);
  }
  TraverseQ(AQueue);
  printf("Front=%d Rear=%d Count=%d\n",AQueue.Front,AQueue.Rear,AQueue.Count);

  printf("---b---\n");
  AddQ(&AQueue,AnItem);
  TraverseQ(AQueue);
  printf("Front=%d Rear=%d Count=%d\n",AQueue.Front,AQueue.Rear,AQueue.Count);

  printf("---c---\n");
  RemoveQ(&AQueue, &AnItem);
  TraverseQ(AQueue);
  printf("Removed Item=%d Front=%d Rear=%d Count=%d\n",AnItem,AQueue.Front,AQueue.Rear,AQueue.Count);

  printf("---d---\n");
  AddQ(&AQueue,25);
  TraverseQ(AQueue);
  printf("Front=%d Rear=%d Count=%d\n",AQueue.Front,AQueue.Rear,AQueue.Count);

  printf("---e---\n");
  AddQ(&AQueue,AnItem);
  TraverseQ(AQueue);
  printf("Front=%d Rear=%d Count=%d\n",AQueue.Front,AQueue.Rear,AQueue.Count);

  printf("---f---\n");
  while (!EmptyQ(AQueue))
  {
    RemoveQ(&AQueue, &AnItem);
    TraverseQ(AQueue);
    printf("Removed Item=%d Front=%d Rear=%d Count=%d\n",AnItem,AQueue.Front,AQueue.Rear,AQueue.Count);
  }

  return 0;

}


void TraverseQ(QueueType Queue)
{
	int current;
	int i;

	printf("Queue: ");
	if(EmptyQ(Queue))
    {
        printf("Empty Queue");
    }
	current = Queue.Front;
	for(i=1;i<=Queue.Count;i++)
        {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
        }
	printf("\n");
}





void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
    Queue->Count = 0;
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Count==0);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return (Queue.Count==QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
*/
{
	if(!EmptyQ(*Queue))
	{
	    Queue->Count--;
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
	    Queue->Count++;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}
