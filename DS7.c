#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */
void PrintNode( Tree NodePtr )
{
   printf(" %d", NodePtr->Element);
}

void Level_order ( Tree T, void (*visit)(Tree ThisNode) );

int main()
{
    Tree T = BuildTree();
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}

Tree BuildTree()
{
	Tree Tree_Base=(Tree)malloc(sizeof(struct TreeNode));
	int d;
	scanf("%d",&d);
	if (!d) return 0;
	Tree_Base->Element=d;
	Tree_Base->Left=BuildTree();
	Tree_Base->Right=BuildTree();
	return Tree_Base;
}

Tree d[200];
int head=0, tail=1;

void Level_order(Tree T, void (*visit)(Tree Thisnode))
{
	d[head]=T;
	if (head==tail || !T) return;
	(*visit)(T);
	if (d[head]->Left) d[tail++]=d[head]->Left;
	if (d[head]->Right) d[tail++]=d[head]->Right;
	head++;
	Level_order(d[head],visit);
	return;
}
