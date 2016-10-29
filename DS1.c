#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

Polynomial Add(Polynomial a, Polynomial b)
{
	int flag=0, fflag=0;
	Polynomial sum=(Polynomial)malloc(sizeof(Polynomial)), ta=a->Next, tb=b->Next, ts=sum;
	while (ta || tb)
	{
		flag=0;
		if (ta && tb && ta->Exponent==tb->Exponent)
		{
			if (ta->Coefficient+tb->Coefficient)
			{
				sum->Next=(Polynomial)malloc(sizeof(Polynomial));
				sum=sum->Next;
				sum->Coefficient=ta->Coefficient+tb->Coefficient;
				sum->Exponent=ta->Exponent;
				sum->Next=0;
			}
			ta=ta->Next;
			tb=tb->Next; 
		}
		else if ((!tb && ta) || (ta && tb && ta->Exponent>tb->Exponent))
		{
				sum->Next=(Polynomial)malloc(sizeof(Polynomial));
				sum=sum->Next;
				sum->Coefficient=ta->Coefficient;
				sum->Exponent=ta->Exponent;
				sum->Next=0;
				ta=ta->Next;
		}		
		else if ((!ta && tb) ||  (ta && tb && ta->Exponent<tb->Exponent))
		{
				sum->Next=(Polynomial)malloc(sizeof(Polynomial));
				sum=sum->Next;
				sum->Coefficient=tb->Coefficient;
				sum->Exponent=tb->Exponent;
				sum->Next=0;
				tb=tb->Next;
		}
	}
	return ts;
}

Polynomial Read() 
{
	Polynomial ext=(Polynomial)malloc(sizeof(Polynomial)), text=ext;
	int dig, texp, tcoe,i;
	scanf("%d", &dig);
	for (i=0; i<dig; i++)
	{
		ext->Next=(Polynomial)malloc(sizeof(Polynomial));
		ext=ext->Next;
		scanf("%d", &tcoe);
		ext->Coefficient=tcoe;
		scanf("%d", &texp);
		ext->Exponent=texp;
		ext->Next=0;
	}
	return text;
}

void Print( Polynomial p ) 
{
	p=p->Next;
	while (p)
	{
		printf("%d %d ", p->Coefficient, p->Exponent);
		p=p->Next;
	}
	return;
}