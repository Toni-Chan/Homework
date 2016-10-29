#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

Operation GetOp()
{
	char *t=(char *)malloc(6*sizeof(char));
	scanf("%s", t);
	if (!strcmp(t,"Push")) 
	return push;
	else if (!strcmp(t,"Inject")) 
	return inject;
	else if (!strcmp(t,"Eject")) 
	return eject;
	else if (!strcmp(t,"Pop")) 
	return pop;
	else if (!strcmp(t,"End")) 
	return end;
}

Deque CreateDeque()
{
	Deque S=(Deque)malloc(sizeof(struct DequeRecord));
	PtrToNode temp=(PtrToNode)malloc(sizeof(struct Node));
	S->Front=temp;
	S->Rear=temp;
	temp->Element=-1;
	temp->Last=temp;
	temp->Next=temp;
	return S;
} 

void PrintDeque(Deque D)
{
	int temp;
	while ((temp=Pop(D))!=ERROR)
	{
		printf("%d ", temp);
	}
	return;
}

int Push( ElementType X, Deque D )
{
	struct Node *temp=(PtrToNode)malloc(sizeof(struct Node));
	if (temp==0) return 0;
	temp->Element=X;
	temp->Next=(D->Front)->Next;
	((D->Front)->Next)->Last=temp;
	(D->Front)->Next=temp;
	temp->Last=D->Front;
	if (D->Front==D->Rear) D->Rear=temp; 
	return 1;
} 

ElementType Pop( Deque D )
{
	if (D->Front==D->Rear) return ERROR;
	PtrToNode temp=(D->Front)->Next;
		int temp_int=temp->Element;
	(D->Front)->Next=temp->Next;
	if (temp->Next==D->Front) D->Rear=D->Front;
	free(temp);
	return temp_int;
} 

int Inject( ElementType X, Deque D )
{
	struct Node *temp=(PtrToNode)malloc(sizeof(struct Node));
	if (temp==0) return 0;
	temp->Element=X;
	temp->Last=D->Rear;
	(D->Rear)->Next=temp;
	D->Rear=temp; 
	temp->Next=D->Front;
	return 1;
} 

ElementType Eject( Deque D )
{
	if (D->Front==D->Rear) return ERROR;
	PtrToNode temp=D->Rear;
	int temp_int=temp->Element;
	D->Rear=temp->Last;
	free(temp);
	return temp_int;
} 
