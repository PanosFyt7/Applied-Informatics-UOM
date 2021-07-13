#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct{
    int AMKA;
    int afm;
    int hlikia;
} BinTreeElementType;



typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void InorderTraversal(BinTreePointer Root);

int main()
{
   char ch;
   int i;
   BinTreePointer Root1, Root2, LocPtr;
   BinTreeElementType person;
   boolean found;

   found=FALSE;
   CreateBST(&Root1);
   CreateBST(&Root2);

     do{
       printf("Give AMKA? ");
       scanf("%d",&person.AMKA);
       printf("Give AFM? ");
       scanf("%d",&person.afm);
       printf("Give age? ");
       scanf("%d",&person.hlikia);

       if(person.hlikia<=60)
       {
           BSTInsert(&Root1,person);
       }
       else
       {
           BSTInsert(&Root2,person);
       }
       printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');

    printf("\nPeople with age less-equal 60\n");
    InorderTraversal(Root1);
    printf("\n");
    printf("\nPeople with age greater than 60\n");
    InorderTraversal(Root2);
    printf("\n");

    for(i=0;i<3;i++)
    {
        printf("Give AMKA: ");
       scanf("%d",&person.AMKA);
       printf("Give age: ");
       scanf("%d",&person.hlikia);

       if(person.hlikia<=60)
       {
           BSTSearch(Root1, person, &found, &LocPtr);
       }
       else
       {
           BSTSearch(Root2, person, &found, &LocPtr);
       }
       if(found)
       {
           if(person.hlikia==LocPtr->Data.hlikia)
           {
               printf("The person with AMKA %d, AFM %d and AGE %d is in the catalogue\n",LocPtr->Data.AMKA,LocPtr->Data.afm,LocPtr->Data.hlikia);
           }
           else
           {
               printf("The person with AMKA %d has AGE %d different from the person you are looking for\n",LocPtr->Data.AMKA,LocPtr->Data.hlikia);
           }
       }
       else
       {
           printf("The person with AMKA %d and AGE %d is Unknown\n",person.AMKA,person.hlikia);
       }
    }
    return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{
    return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.AMKA<LocPtr->Data.AMKA)
            LocPtr = LocPtr ->LChild;
        else if (Item.AMKA>LocPtr ->Data.AMKA)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item.AMKA);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr->Data.AMKA=Item.AMKA;
        LocPtr->Data.afm=Item.afm;
        LocPtr->Data.hlikia=Item.hlikia;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.AMKA < Parent ->Data.AMKA)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,BinTreePointer *LocPtr)
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue.AMKA < (*LocPtr)->Data.AMKA)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue.AMKA > (*LocPtr)->Data.AMKA)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d, %d, %d) ",Root->Data.AMKA,Root->Data.afm,Root->Data.hlikia);
        InorderTraversal(Root->RChild);
    }
}

