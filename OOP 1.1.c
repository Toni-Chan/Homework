#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 1e8
/*#define ElementType int*/

typedef enum { push, pop, inject, eject, end, rev, merge, create, output, insert, take} Operation; 
typedef enum { _int, _long, _short, _float, _double, _char, _string, _pointer} Data_type; 
struct Etype
{
	void *Content;
	Data_type DataCategory;
};

typedef struct Etype *ElementType;

typedef struct Node *PtrToNode;

struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};

typedef struct DequeRecord *Deque;

struct DequeRecord {
    PtrToNode Front, Rear;
};

Deque *DeqRecRecorder; 

void PrintX(ElementType tp)
{
	switch (tp->DataCategory)
	{
	case _int: case _long: case _short:
		printf("%d ", *(int*)(tp->Content));
		break;
	case _float:
		printf("%f ", *(float*)(tp->Content));
		break;
	case _double:
		printf("%lf ", *(double*)(tp->Content));
		break;
	case _char:
		printf("%c ", *(char*)(tp->Content));
		break;
	case _string:
		printf("%s ", (char*)(tp->Content));
		break;
	default:
		break;
	}
	printf("\n");
	return;
}

Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );
int Insert (ElementType X, Deque D, int (*Compare)(ElementType, ElementType));
ElementType Take(Deque D, int(*Compare)(ElementType));
int Merge(Deque A, Deque B);
int Reverse(Deque D);
int DestructDeque(Deque D);
ElementType ScanX();
int ERRflag=0;

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int d_count=0;

void PrintInstruction()
{
	char *t="Type \042Create\042 to begin\n Available functions: \nPush (Entry)(List No)\nPop (List No)\nInject (Entry)(List No)\nEject (List No)\nInsert (Entry)(List No)\nTake (List No)\nReverse (List No)\nMerge (List a, List b)\nOutput (List No)\nEnd\n";
	printf("%s", t);
} 

Deque FindDeque(int k)
{
	if (k>d_count) return 0;
	return DeqRecRecorder[k]; 
}

int Compare(ElementType a, ElementType b)
{
	if (a->DataCategory!=b->DataCategory) return 1;
	return a->Content>b->Content;
}

int Compare2(ElementType a)
{
	return (int)(a->Content)>10;
}

void Eq(ElementType to, ElementType fro)
{
	*to=*fro;
} 

int main()
{
    ElementType X;
    Deque D;
    int done = 0, Current_Deque, Deque_Temp;
    DeqRecRecorder=(Deque *)malloc(100*sizeof(Deque));
	PrintInstruction();
    while (!done) {
    	ERRflag=0;
        switch(GetOp()) {
        case create:
        	D=CreateDeque();
        	printf("Linked List %d initialized\n", d_count);
        	break;
        	
		case push: 
			X=ScanX();
            scanf("%d",&Current_Deque);
            D=FindDeque(Current_Deque); 
			if (!D) printf("No Such List!\n");
            else 
			{
 				if (!Push(X, D)) printf("Memory of List %d is Full!\n", Current_Deque);
			}
            break;
            
        case pop:
            scanf("%d", &Current_Deque);
            D=FindDeque(Current_Deque);
			if (!D) printf("No Such List!\n");
            else 
			{
			X = Pop(D);
            if (ERRflag) printf("List %d is Empty!\n", Current_Deque);
			else PrintX(X);
			}
            break;
            
        case inject: 
		    X=ScanX();
			scanf("%d", &Current_Deque);
            D=FindDeque(Current_Deque);
			if (!D) printf("No Such List!\n");
            else 
			{
            if (!Inject(X, D)) printf("Memory of List %d is Full!\n", Current_Deque); 
			}
            break;
            
        case eject:
            scanf("%d", &Current_Deque);
            D=FindDeque(Current_Deque);
			if (!D) printf("No Such List!\n");
            else 
			{
			X = Eject(D);
            if (ERRflag) printf("List %d is Empty!\n", Current_Deque);
			else PrintX(X);
			}
            break;
            
   		case insert: 
   			X=ScanX();
			scanf("%d", &Current_Deque);
            D=FindDeque(Current_Deque);
			if (!D) printf("No Such List!\n");
            else 
			{
            if (!Insert(X, D, Compare)) printf("Memory of List %d is Full!\n", Current_Deque); 
			}
            break;
            
        case take:
            scanf("%d", &Current_Deque);
            D=FindDeque(Current_Deque);
			if (!D) printf("No Such List!\n");
            else 
			{
			X = Take(D,Compare2);
            if (ERRflag) printf("Cannot Find Any at List %d!\n", Current_Deque);
			else PrintX(X);
			}
            break;
            
        case rev:
        	scanf("%d", &Current_Deque);
            D=FindDeque(Current_Deque);
			if (!D) printf("No Such List!\n");
            else 
			{
			if (!Reverse(D)) printf("Cannot reverse List %d!\n", Current_Deque); 
			}
        	break;
        	
        case merge:
        	scanf("%d %d", &Current_Deque, &Deque_Temp);
        	Deque Dtemp=FindDeque(Deque_Temp);
            D=FindDeque(Current_Deque);
			if (!D) printf("No Such List!\n");
            else 
			{
            if (!Merge(D,Dtemp)) printf("Cannot merge Lists %d and %d!\n",  Current_Deque, Deque_Temp);
			}
        	break;
        	
        case output:
        	scanf("%d", &Current_Deque);
            D=FindDeque(Current_Deque);
			if (!D) printf("No Such List!\n");
            else 
			{
            PrintDeque(D);
			}
            break;
            
        case end:
        	Ende();
        	done=1;
        	break;
        }
    }
    return 0;
}

Operation GetOp()
{
	char *t=(char *)malloc(10*sizeof(char));
	scanf("%s", t);
	if (!strcmp(t,"Push")) 
	return push;
	else if (!strcmp(t,"Inject")) 
	return inject;
	else if (!strcmp(t,"Eject")) 
	return eject;
	else if (!strcmp(t,"Pop")) 
	return pop;
	else if (!strcmp(t,"Output")) 
	return end;
	else if (!strcmp(t,"Merge"))
	return merge;
	else if (!strcmp(t,"Reverse"))
	return rev;
	else if (!strcmp(t,"Create"))
	return create;
}

ElementType ScanX()
{
	char *t=(char *)malloc(50*sizeof(char));
	ElementType d=(ElementType)malloc(sizeof(struct Etype));
	scanf("%s", t);
	int tleng = 0;
	char *tstt = t;
	while (*t)
	{
		tleng++;
		t++;
	}
	t = tstt;
	t[tleng] = 0;
	int isint=0, isfloat=0;
	double tdouble=0,dot=0;
	int tint=0;
	char tchar=0;
	while (t)
	{
		switch(*t)
		{
			case '.':
			dot=0.1;
			tdouble=tint;
			break;
			
			case '1': case '2': case '3': case '4': case '5':
			case '6': case '7': case '8': case '9': case '0':
			if (dot!=0)
			{
				tdouble+=(*t-48)*dot;
				dot*=0.1;
			}
			else
			{
				tint*=10;
				tint+=*t-48;
			}
			break;
			
			case 0:
			if (d->DataCategory==_char) break;
			if (dot!=0) 
			{
				d->DataCategory=_double;
				double *content=(double *)malloc(sizeof(double));
				*content = tdouble;
				d->Content=content;
			}
			else
			{
				d->DataCategory=_int;
				int *content = (int *)malloc(sizeof(int));
				*content = tint;
				d->Content=content;
			}
			return d;
			break;
			
			default:
			if (!*(t+1))
			{
				d->DataCategory=_char;
				char *content = (char *)malloc(sizeof(char));
				d->Content=content; 
				break;
			}
			d->DataCategory=_string;
			char *content = (char *)malloc(strlen(tstt)*sizeof(char));
			strcpy(content, tstt);
			d->Content = content;
			return d;
			break;
		}
		t++;
	}
	return d;
}

Deque CreateDeque()
{
	Deque S=(Deque)malloc(sizeof(struct DequeRecord));
	PtrToNode temp=(PtrToNode)malloc(sizeof(struct Node));
	S->Front=temp;
	S->Rear=temp;
	temp->Element=NULL;
	temp->Last=temp;
	temp->Next=temp;
	d_count++;
	DeqRecRecorder[d_count]=S;
	return S;
} 

void PrintDeque(Deque D)
{
	PtrToNode temp=(D->Front)->Next;
	while (temp->Next!=D->Front)
	{
		ElementType tp=temp->Element;
		PrintX(tp);
		temp=temp->Next;
	}
	return;
}

int Push( ElementType X, Deque D )
{
	struct Node *temp=(PtrToNode)malloc(sizeof(struct Node));
	if (!temp) return 0;
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
	if (D->Front==D->Rear)
	{
		ERRflag=1;
		return 0; 
	}
	PtrToNode temp=(D->Front)->Next;
	ElementType temp_int=temp->Element;
	(D->Front)->Next=temp->Next;
	if (temp->Next==D->Front) D->Rear=D->Front;
	free(temp);
	return temp_int;
} 

int Inject( ElementType X, Deque D )
{
	struct Node *temp=(PtrToNode)malloc(sizeof(struct Node));
	if (!temp) return 0;
	temp->Element=X;
	temp->Last=D->Rear;
	(D->Rear)->Next=temp;
	D->Rear=temp; 
	temp->Next=D->Front;
	return 1;
} 

ElementType Eject( Deque D )
{
	if (D->Front==D->Rear) 
	{
		ERRflag=1;
		return 0;
	}
	PtrToNode temp=D->Rear;
	ElementType temp_int=temp->Element;
	D->Rear=temp->Last;
	free(temp);
	return temp_int;
} 

int Reverse (Deque D)
{
	PtrToNode temp=(D->Front)->Next, temp2, tlast=D->Front, tempstart=temp;
	if (temp==D->Front) return 0;
	while (temp!=D->Front)
	{
		temp2=temp->Next;
		temp->Next=temp->Last;
		temp->Last=temp2;
		temp=temp2;
	}
	(D->Front)->Next=D->Rear;
	(D->Rear)->Last=D->Front;
	D->Rear=tempstart;
	tempstart->Next=D->Front;
	return 1;
}

int Merge(Deque A, Deque B)
{
	PtrToNode temp=(B->Front)->Next;
	(A->Rear)->Next=temp;
	temp->Last=A->Rear;
	A->Rear=B->Rear;
	(A->Rear)->Next=A->Front;
	return 1;
}

int Ende()
{
	int i;
	for (i=0; i<d_count; i++)
	free(DeqRecRecorder[i]);
	return -1; 
}

int Insert (ElementType X, Deque D, int (*Compare)(ElementType, ElementType))
{
	struct Node *temp=(PtrToNode)malloc(sizeof(struct Node));
	if (!temp) return 0;
	temp->Element=X;
	struct Node *temp2=(D->Front)->Next;
	while (temp2->Next!=D->Front && !Compare(temp2->Element, temp->Element)) temp2=temp2->Next;
	temp->Next=temp2->Next;
	temp2->Next=temp;
	(temp2->Next)->Last=temp;
	temp->Last=temp2->Last;
	if (temp->Next==D->Front || D->Front==D->Rear) D->Rear=temp; 
	
	return 1;
}

ElementType Take(Deque D, int(*Compare)(ElementType))
{
	if (D->Front==D->Rear) 
	{
		ERRflag=1;
		return 0;
	}
	PtrToNode temp=(D->Front)->Next;
	while (temp!=D->Front && !Compare(temp->Element)) temp=temp->Next;
	if (temp==D->Front) 
	{
		ERRflag=1;
		return 0;
	}
	ElementType temp_int;
	temp_int=temp->Element;
	(temp->Last)->Next=temp->Next;
	(temp->Next)->Last=temp->Last;
	free(temp);
	return temp_int;
}
