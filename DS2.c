#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Reverse(List L)
{
	List tres=L;
	Position Last=0, nexxt=tres->Next,tnexxt=nexxt;
	if (nexxt==0) return L;
	while (tres!=0)
	{
		Last=tres;
		tres=nexxt;
		if (tres==0) break;
		nexxt=tres->Next;
		tres->Next=Last;
	} 
	L->Next=Last;
	tnexxt->Next=0;
	return L;
}

List Read()
{
	List ext=(List )malloc(sizeof(List )), text=ext;
	int dig, texp, tcoe,i;
	scanf("%d", &dig);
	for (i=0; i<dig; i++)
	{
		ext->Next=(List)malloc(sizeof(List));
		ext=ext->Next;
		scanf("%d", &tcoe);
		ext->Element=tcoe;
		ext->Next=0;
	}
	return text;
}


void Print( List p ) 
{
	p=p->Next;
	while (p)
	{
		printf("%d ", p->Element);
		p=p->Next;
	}
	printf("\n");
	return;
}