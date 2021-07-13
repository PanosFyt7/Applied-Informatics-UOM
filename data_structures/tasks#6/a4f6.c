#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HMax 9           /*     �� ������� ��� ������ HashTable
                                ���������� ��� �� 5 */
#define VMax 30             /*�� ������� ��� ������,
                                ���������� ��� �� 30 */
#define EndOfList -1        /* ������ ��� ����������� �� ����� ��� ������
                                ��� ��� ���� ��������� ��������� */

typedef struct{
   char phone[11];
   int type;
} ListElementType;  /*����� ��������� ��� �� �������� ��� ������
                            * ���������� ����� int */
typedef char KeyType[32];
typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // ������� ������� ���� ��� ��������� ���������
    int Size;                // ������ �������� ��� ������ List
	int SubListPtr;          // D������� �� ��� �������� ���������
    int StackPtr;           // ������� ���� ��� ����� �������� ���� ��� ������ List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
void Print_HashList(HashListType HList);
void PrintPinakes(HashListType HList);
void Search_HashList_By_Subject(HashListType HList, int code);
void BuildHashList(HashListType *HList);
int findAverage(KeyType s);

int main()
{
   char ch;
   HashListType HList;
   ListElm AnItem;
   KeyType AKey;
   int Loc, Pred;
   int code;
   char surname[20];

   printf("1. Create HashList\n");
   BuildHashList(&HList);
   PrintPinakes(HList);

   printf("2. Insert new teacher\n");
   do
            {
   	            printf("Enter teacher's name: ");
                scanf("%s", AnItem.RecKey); getchar();
                printf("Enter teacher's surname: ");
                scanf("%s", surname); getchar();

                strcat(AnItem.RecKey, " ");
                strcat(AnItem.RecKey, surname);

                printf("Enter teacher's phone: ");
                scanf("%s", AnItem.Data.phone); getchar();
                printf("Enter teacher code: ");
                scanf("%d", &AnItem.Data.type);
                AnItem.Link=EndOfList;
                AddRec(&HList, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
   PrintPinakes(HList);

   printf("3. Delete a teacher\n");
   printf("Enter teacher's name: ");
    scanf("%s", AKey); getchar();
    printf("Enter teacher's surname: ");
    scanf("%s", surname); getchar();

    strcat(AKey, " ");
    strcat(AKey, surname);

    DeleteRec(&HList, AKey);
    PrintPinakes(HList);

    printf("4. Search for a teacher\n");
    printf("Enter teacher's name: ");
    scanf("%s", AnItem.RecKey); getchar();
    printf("Enter teacher's surname: ");
    scanf("%s", surname); getchar();

    strcat(AnItem.RecKey, " ");
    strcat(AnItem.RecKey, surname);

    SearchHashList(HList,AnItem.RecKey,&Loc,&Pred);
    if(Loc!=-1)
    {
        printf("[%s, %s, %d]\n",HList.List[Loc].RecKey,HList.List[Loc].Data.phone,HList.List[Loc].Data.type);
    }
    else
    {
        printf("DEN YPARXEI EGGRAFH ME KLEIDI %s\n",AnItem.RecKey);
    }

    printf("\n5. Search by subject\n");
    printf("Enter code: ");
    scanf("%d", &code);
    Search_HashList_By_Subject(HList,code);

    return 0;
}

void Search_HashList_By_Subject(HashListType HList, int code)
{
    int i,SubIndex;

    printf("List of teachers with subject code %d: \n", code);
    for (i=0; i<HMax;i++)
    {
        SubIndex = HList.HashTable[i];
        while ( SubIndex != EndOfList )
            {
                if(HList.List[SubIndex].Data.type==code)
                {
                    printf("%d: [%s, %s, %d]\n", SubIndex, HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.phone, code);
                }
                SubIndex = HList.List[SubIndex].Link;
            }
    }
}


void BuildHashList(HashListType *HList)
{
    int nscan;
    ListElm AnItem;
    FILE *fp;
    char surname[20],termch;

    CreateHashList(HList);
    fp=fopen("i4f6.txt","r");
    if(fp!=NULL)
    {
        while(TRUE)
        {
           nscan=fscanf(fp,"%10[^,],%20[^,],%10[^,],%d%c", AnItem.RecKey,surname,AnItem.Data.phone,&AnItem.Data.type,&termch);
           if(nscan==EOF)
             break;
           if(nscan!=5 || termch!='\n')
             printf("Error\n");
           else
            {
                 strcat(AnItem.RecKey, " ");
                 strcat(AnItem.RecKey, surname);
                 AddRec(&(*HList), AnItem);
            }
        }
    }
    fclose(fp);
}


int findAverage(KeyType s)
{
    char first,last;

    first=toupper(s[0]);
    last=toupper(s[strlen(s)-1]);
    return ((first - 64) + (last - 64)) / 2;
}


void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d, ",HList.HashTable[i]);

	printf("\nHash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %s, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}

int HashKey(KeyType Key)
/* �������:    ��� ���� Key ���� ��������.
   ����������: ������� ��� ���� ��������������� HValue ��� �� ������ Key.
   ����������: ��� ���� ��������������� HValue
*/
{
    int avg;
	/*�� ��������� ��� �� KeyType ��� ����� ��������
	�� ������ �� ������������ ��������� �� ������ �� ������*/
	avg=findAverage(Key);

	return avg % HMax;
}

void CreateHashList(HashListType *HList)
/* ����������: ���������� ��� ���� HList.
   ����������: ��� ���� HList
*/
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=0;       //������� ��� ������ ��� ������� ��� ��������� ������

    /*����������� ��� ������ HashTable ��� ����� HList ���� ���� ��������� ���
        �� ���� �� ���� EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //���������� ��� ������� ��� ��������� ������ ��� ����� HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* �������:    ��� ���� HList.
   ����������: ������� �� � ����� List ��� ����� HList ����� ������.
   ����������: TRUE �� � ����� List ����� ������, FALSE �����������.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ���� �������� ���������.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ��� ������������
                �������� ���� ��������
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey,KeyArg)==0)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ��� ���� HList.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ���
                ������������ �������� ��� ��������� ���� ����� ������.
                �� ��� ������� ������� �� ������ KeyArg ���� Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* �������:    ��� ���� HList ��� ��� ������� InRec.
   ����������: ������� ��� ������� InRec ��� ����� List, �� ��� ����� ������,
                ��� ���������� �� ���� HList.
   ����������: ��� ������������� ���� HList.
   ������:     ������ ������� ������, �� � List ����� ������, �����������,
                �� ������� ��� ������� �� �� ���� ������,
                �������� ����������� ���������
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}

