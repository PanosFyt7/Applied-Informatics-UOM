#include <stdio.h>
#include <stdlib.h>

#define StackLimit 50

typedef char StackElementType;

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
    StackType S;
    boolean valid;
    boolean flag;
    char ch;
    StackElementType item;

    flag=FALSE;
    valid=TRUE;
    CreateStack(&S);


    printf("Enter a string:\n");
    scanf("%c", &ch); getchar();

    if(ch!='#')
    {
        while(ch!='#' && valid==TRUE)
        {
            if(flag==FALSE)
            {
                if(ch=='C')
                {
                    flag=TRUE;
                    scanf("%c", &ch); getchar();
                }
                else
                {
                    Push(&S,ch);

                    scanf("%c", &ch); getchar();
                }
            }
            else
            {
                if(EmptyStack(S)==FALSE)
                {
                    Pop(&S,&item);

                    if(item!=ch)
                    {
                        valid=FALSE;
                    }
                    else
                    {
                        scanf("%c", &ch); getchar();
                    }
                }
                else
                {
                    valid=FALSE;
                }
            }

        }
        if(valid==TRUE && EmptyStack(S))
        {
            printf("TRUE");
        }
        else
        {
        printf("FALSE");
        }
    }

    return 0;
}

void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
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
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

boolean EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}
