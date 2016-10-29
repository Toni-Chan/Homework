#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode{
    int Key;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* details omitted */
int CheckBST ( BinTree T, int K );

int main()
{
    BinTree T;
    int K, out;

    T = BuildTree();
    scanf("%d", &K);
    out = CheckBST(T, K);
    if ( out < 0 )
        printf("No.  Height = %d\n", -out);
    else
        printf("Yes.  Key = %d\n", out);
    return 0;
}

BinTree BuildTree()
{
	BinTree Tree_Base=(BinTree)malloc(sizeof(struct TNode));
	int d;
	scanf("%d",&d);
	if (!d) return 0;
	Tree_Base->Key=d;
	Tree_Base->Left=BuildTree();
	Tree_Base->Right=BuildTree();
	return Tree_Base;
}

int CheckBST(BinTree T, int K)
{	
	if (!T) return 0;
	static int ISBST = 1;
	static int D=0;
	static int XD = 0;
	static int count = 0;
	static int Seq = 0;
	D++;
	if (XD < D) XD = D;
	if ((T->Left && (T->Left)->Key>=T->Key) || (T->Right && (T->Right)->Key<=T->Key)) ISBST=0;
	CheckBST(T->Right,K);
	count++;
	if (count == K) Seq = T->Key;
	CheckBST(T->Left,K);
	if (D == 1 && ISBST)
		return Seq;
	else if (D == 1 && !ISBST)
		return -XD;
	else
	{
		D--;
		return -1;
	}
}

