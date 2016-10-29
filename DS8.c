#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */

void Post_Order_Trav(Tree T1);
int d,nnode,tnnode=0;

int main()
{
    Tree T1;
	scanf("%d", &d);
	nnode = 2 * d;
    T1 = BuildTree();
	Post_Order_Trav(T1);
	return 0;
}

Tree BuildTree()
{
	if (tnnode >= d) return 0;
	Tree Tree_Base=(Tree)malloc(sizeof(struct TreeNode));
	int d;
	char* Command = (char *)malloc(5 * sizeof(char));
	scanf("%s", Command);
	if (!strcmp(Command, "Pop")) 
		return 0;
	scanf("%d", &d);
	Tree_Base->Element = d;
	tnnode ++;
	Tree_Base->Left=BuildTree();
	Tree_Base->Right=BuildTree();
	return Tree_Base;
}

void Post_Order_Trav(Tree T1)
{
	static int depth = 0;
	if (!T1) return;
	Post_Order_Trav(T1->Left);
	Post_Order_Trav(T1->Right);
	printf("%d", T1->Element);
	depth++;
	if (depth != d) printf(" ");
	return;
}