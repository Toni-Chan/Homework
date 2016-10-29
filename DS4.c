#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

Operation GetOp()
{
	char *t=(char *)malloc(6*sizeof(char));
	scanf("%s", t);
	if (!strcmp(t,"Push")) 
	return push;
	else if (!strcmp(t,"Pop")) 
	return pop;
	else if (!strcmp(t,"End")) 
	return end;
}
void PrintStack( Stack S, int Stacknum )
{
	int temp;
	while (!IsEmpty(S,1))
	{
		temp=Top_Pop(S,1);
		printf("%d ", temp);
	}
	printf("\n");
	while (!IsEmpty(S,2))
	{
		temp=Top_Pop(S,2);
		printf("%d ", temp);
	}
	return;
}

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
           scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case pop:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

/* Your function will be put here */

Stack CreateStack( int MaxElements )
{
	Stack t=(Stack)malloc(sizeof(struct StackRecord));
	t->Array=(int *)malloc(MaxElements*sizeof(int));
	t->Capacity=MaxElements;
	t->Top1=0;
	t->Top2=MaxElements-1;
	return t;
}

int IsEmpty( Stack S, int Stacknum )
{
	if (Stacknum==1)
	return S->Top1==0;
	else
	return S->Top2==S->Capacity-1;
}

int IsFull( Stack S )
{
	return S->Top1>S->Top2;
}

int Push( ElementType X, Stack S, int Stacknum )
{
	if (IsFull(S)) return 0;
	if(Stacknum==1)
	{
		*(S->Array+S->Top1)=X;
		S->Top1++;
	}
	else if(Stacknum==2)
	{
		*(S->Array+S->Top2)=X;
		S->Top2--;
	}
	return 1;
}

ElementType Top_Pop( Stack S, int Stacknum )
{
	if (IsEmpty(S,Stacknum)) return ERROR;
	int temp;
	if (Stacknum==1)
	{
		S->Top1--;
		temp=*(S->Array+S->Top1);
	}
	else if (Stacknum==2)
	{
		S->Top2++;
		temp=*(S->Array+S->Top2);
	}
	return temp;
}
