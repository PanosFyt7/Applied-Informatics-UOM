#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// ������ �����
typedef struct
{
    int code;
    int recNo;
} BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef struct
{
    int code;
    char surname[20];
    char name[20];
    char sex;
    int year;
    float grade;
} StudentT;

typedef enum {
    FALSE, TRUE
} boolean;

// ������ �����������
void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTInorder(BinTreePointer Root);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);

int BuildBST(BinTreePointer *Root);
void writeNewStudents(BinTreePointer *Root, int *size);
void printStudentsWithGrade(float theGrade);
void PrintStudent(int recNum);

int main()
{
   // ������ ����������
   BinTreePointer ARoot, LocPtr;
   float theGrade;
   int size; // ������ ������ ��� ���
   StudentT student;
   boolean Found;
   BinTreeElementType key;


   // ������� 1
   printf("Q1. Build BST from a file\n");
   size=BuildBST(&ARoot); // ���������� ���������� ��� ��������� ������� ������

   // ������� 2
   printf("Q2. Print size and BST\n");
   printf("Size=%d\n",size);
   printf("Nodes of BST\n");
   RecBSTInorder(ARoot); // �������� ��� ������ ������� (�� ������� �������)

   // ������� 3
   printf("\nQ3. Write new students, update file and BST\n");
   writeNewStudents(&ARoot, &size); // �������� ���� ��������

   // ������� 4
   printf("Q4. Print size and BST\n");
   printf("Size=%d\n",size);
   printf("Nodes of BST\n");
   RecBSTInorder(ARoot); // �������� ��� ������ ������� (�� ������� �������)

   // ������� 5
   printf("\nQ5. Search for a student\n");
   printf("Give student's code? "); // ������� �� ��
   scanf("%d",&key.code);
   RecBSTSearch(ARoot,key,&Found,&LocPtr); // ��������� ��� �������
   if (Found)
   { // key.recNo = LocPtr->Data.recNo
     PrintStudent(LocPtr->Data.recNo);}
   else
   {printf("Student with code %d not found!\n",LocPtr->Data.code);}

   // ������� 6
   printf("Q6. Print size and BST\n");
   printf("Size=%d\n",size);
   printf("Nodes of BST\n");
   RecBSTInorder(ARoot);// �������� ��� ������ ������� (�� ������� �������)

   // ������� 7
   printf("\nQ7. Print students with grades >= given grade\n");
    printf("Give the grade: ");
    scanf("%f", &theGrade);
    printStudentsWithGrade(theGrade);


   return 0;
}

// �����������

int BuildBST(BinTreePointer *Root)
{
  FILE *fp;
  int size; // ������ �������� �������
  int nscan;
  char termch;
  BinTreeElementType indexRec; // ������� ������� ��� �� ���
  StudentT student; // ������ ��� ��� �������� ��� ��������� ������� ��� �� ������

  CreateBST(Root);

  fp = fopen("foitites.dat" ,"r"); // ������ ������ ��� ��������
  size=0; // ������������ ��� size

  if(fp == NULL) // �� �� ������ ��� ������, ����� ������ ���������
      {printf("Problem opening file\n");
      exit(1);}
  else // �� �� ������ ������ ��������
    {
     while(TRUE)
     {
         nscan = fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name,student.surname,&student.sex,&student.year,&student.grade,&termch); // ������� �� ��� �� ������ ��� ������� �������
         if ( nscan == EOF ) // �� ������ ��� ����� ��� �������
            {printf("Tree built successfully!\n"); // ����������
            break;} // ����� �� �����
         if ( nscan != 7||termch!='\n' ) // �� � �������� ��� �������� ��� ���� ��������
            {printf("Error\n");break;} // �������� ������. ������ ��������
         else // ������
         {
             indexRec.code=student.code; // ���������� ��� indexRec ��� �� ��� ��������
             indexRec.recNo=size; // ���������� ���� indexRec ��� �������� ������ ��������
             RecBSTInsert(&(*Root),indexRec); // �������� ��� �������� ��� ������� ��� ���
             size++; // ������ ���� 1 �� ������ ��� ��������
         }
     }

    }
  fclose(fp); // ������ �� ������
  return size; // ��������� �� size
}

void PrintStudent(int recNum)
{
    FILE *fp;
    int nscan;
    int lines; // ������� ��� ������� ��� �����������
    char termch;
    StudentT student; // ������� ��� ��� �������� ��� ��������� ��� ������� ��� �� ������
    BinTreeElementType indexRec;

    lines=0; // ������������ ��� lines

    fp=fopen("foitites.dat","r"); // ������ �� ������

    if(fp == NULL) // �� ��� ������ �� ������
      printf("Problem opening file"); // �������� ������
    else // �� ������ �����
      {
         while(lines<=recNum) // ��� ��� ������ ��� ������ ��� ���������� �������
         {
          nscan = fscanf(fp, "%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name, student.surname,&student.sex,&student.year,&student.grade,&termch); // ������� ��� �� ������ ��� ������� ��� �������
          if ( nscan == EOF ) // �� � �������� ������ ��� ����� ��� �������
            {break;} // ����� �� �����
          if ( nscan != 7||termch!='\n' ) // �� � �������� ��� ������� ��� ���� ��������
            { printf("Error\n");} // �������� �����

          lines++; // ������ �� ������ ��� �������

          }
          if(lines==recNum+1)
        printf("%d,%s,%s,%c,%d,%.1f\n",student.code,student.name, student.surname,student.sex,student.year,student.grade); // �������� ��� �� �������� ��� �������
        fclose(fp); // ������ �� ������
    }

}


void printStudentsWithGrade(float theGrade)
{
    // ������ ����������
    FILE *fp;
    int nscan;
    char termch;
    StudentT student;

    fp = fopen("foitites.dat" ,"r"); // ������ ������ ��� ��������

    if(fp == NULL) // �� ������� �� ������� �� ������
      printf("Problem opening file"); // ������ ������
    else // �� ������ �� ��������
      {
         while(TRUE)
         {
          nscan = fscanf(fp, "%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name, student.surname,&student.sex,&student.year,&student.grade,&termch); // ������� �� ������ ��� ��� ������� ��� �������
          if ( nscan == EOF ) // �� ���� ������ ��� ����� ��� �������
            {break;} // ����� �� �����
          if ( nscan != 7||termch!='\n' ) // �� � �������� ��� �������� ��� ���� ��������
            { printf("Error\n");} // ����� ����� �����. ��������
          else // ������
           {
             if (student.grade>=theGrade) // �� � ������ ��� ������� ����� >= theGrade
             {
                 printf("%d,%s,%s,%c,%d,%.1f\n",student.code,student.name, student.surname,student.sex,student.year,student.grade); // �������� �� �������� ��� �������
             }
           }
          }

        fclose(fp); // ������ �� ������
    }


}

void writeNewStudents(BinTreePointer *Root, int *size)

{
   BinTreePointer LocPtr;
   StudentT student; // ������� ��� �������� ��� ��������� ������� ��� �� ������
   boolean Found;
   int code;
   char ch;
   FILE *fp;
   BinTreeElementType indexRec; // ������� ������� ��� �� ���


    fp=fopen("foitites.dat","a");
    if(fp == NULL) // �� ������� �� ������� �� ������
      printf("Problem opening file"); // ������ ������
    else // �� ������ �� ��������
      {
          do // ������������
            {
                 printf("Give student's AM? "); // ������� �� ��
                 scanf("%d",&indexRec.code);
                 RecBSTSearch(*Root,indexRec,&Found,&LocPtr); // ��������� ��� ������� �� �� �������� ��
                 if(!Found) // �� �� �������
                 {
                 student.code=indexRec.code; // ���������� �� �� ���� ������� ��� �� ������
                 printf("Give student surname? "); // ������� �������
                 scanf("%s",student.surname); getchar(); // �������, ��� &
                 printf("Give student name? "); // ������� �����
                 scanf("%s",student.name); getchar() ;
                 printf("Give student sex F/M? "); // ������� ����
                 scanf("%c",&student.sex); getchar();
                 printf("Give student's registration year? "); // ������� ����
                 scanf("%d",&student.year);
                 printf("Give student's grade? "); // ������� �����
                 scanf("%f",&student.grade);

                 indexRec.code = student.code;
                 indexRec.recNo = *size;
                 RecBSTInsert(Root,indexRec); // �������� ��� ������� ��� ���
                 fprintf(fp,"%d,%s,%s,%c,%d,%.1f\n",student.code,student.name, student.surname,student.sex,student.year,student.grade); // ������� ��� ������
                 (*size)++; // ������ ������� �������� ���� 1
                 printf("Size=%d\n",*size);
                 }
                 else
                  {printf("Student with code AM %d already exists!\n",indexRec.code);}


            printf("\nContinue Y/N: ");
            do // ������������
            {

            scanf("%c", &ch); // ������� ��� ��������� ch
            } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y'); // ��� � ���������� ��� ����� N � �

       } while (toupper(ch)!='N'); // ��� � ���������� ��� ����� �
       }

    fclose(fp); // ������ �� ������
}

void RecBSTInorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("(%d, %d), ",Root->Data.code,Root->Data.recNo); // '������ ��� printf("%d ",Root->Data);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}

void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{
    return (Root==NULL);
}


void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
*/
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.code < Root->Data.code)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.code > Root->Data.code)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item.code < (*Root) ->Data.code)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.code > (*Root) ->Data.code)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}
