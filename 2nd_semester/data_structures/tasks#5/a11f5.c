#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef char BinTreeElementType[20];

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
void CreateDictionary(BinTreePointer *Root, FILE *fp);
int SpellingCheck(BinTreePointer Root, FILE* fp);


int main()
{
   BinTreePointer ARoot,LocPtr;
   boolean Found;

   FILE* fp1;
   FILE* fp2;

   fp1=fopen("i112f5.txt","r");

   fp2=fopen("i111f5.txt","r");

   CreateBST(&ARoot);

   CreateDictionary(&ARoot,fp1);

   printf("**********Dictionary**********\n");
   InorderTraversal(ARoot);

   printf("\n**********Not in Dictionary**********\n");
   printf("Number of words not in dictionary: %d",SpellingCheck(ARoot,fp2));
   return 0;

}


void CreateDictionary(BinTreePointer *Root, FILE *fp)
{
    BinTreeElementType AnItem;
    int count=1;

    while(count==1)
    {
	    count=fscanf(fp,"%s",AnItem);
        if (count==EOF) break;
            else BSTInsert(Root,AnItem);
    }
}

int SpellingCheck(BinTreePointer Root, FILE* fp)
{
    int count,amount;
    BinTreeElementType temp;
    BinTreeElementType AnItem;
    BinTreePointer LocPtr;
    boolean flag;

    amount=0;
    while(!feof(fp))
    {
        count=fscanf(fp,"%s",AnItem);

        BSTSearch(Root, AnItem,&flag,&LocPtr);
        if (flag==FALSE)
        {
            printf("%s\n",AnItem);
            amount++;
        }
    }
    return amount;
}




void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;

    while (!Found && LocPtr!=NULL)
    {
        Parent=LocPtr;
        if (strcmp(Item,LocPtr->Data)<0)
            LocPtr=LocPtr->LChild;
        else if (strcmp(Item,LocPtr->Data)>0)
            LocPtr=LocPtr ->RChild;
        else
            Found=TRUE;
    }
    if (Found==TRUE)
    {
        printf(" To %s EINAI HDH STO DDA  \n", Item);
    }
    else
    {
        LocPtr=(BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr->Data,Item);
        LocPtr->LChild=NULL;
        LocPtr->RChild=NULL;
        if (Parent==NULL)
            *Root=LocPtr;
        else if(strcmp(Item,Parent->Data)<0)
            Parent->LChild=LocPtr;
        else
            Parent->RChild=LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,BinTreePointer *LocPtr)
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr)!=NULL)
    {
        if (strcmp(KeyValue,(*LocPtr)->Data)<0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue,(*LocPtr)->Data)>0)
                (*LocPtr)=(*LocPtr)->RChild;
            else (*Found)=TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,BinTreePointer *LocPtr, BinTreePointer *Parent)
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue < (*LocPtr)->Data)
        {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue > (*LocPtr)->Data)
            {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }
}

void InorderTraversal(BinTreePointer Root)
{
   if (Root!=NULL)
    {
        InorderTraversal(Root->LChild);
        printf("%s\n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}


