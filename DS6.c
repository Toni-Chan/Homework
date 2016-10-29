#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */

int Isomorphic( Tree T1, Tree T2 );

int main()
{
    Tree T1, T2;
    T1 = BuildTree();
    T2 = BuildTree();
    printf(“%d\n”, Isomorphic(T1, T2));
    return 0;
}

Tree BuildTree()
{
	Tree Tree_Base=(Tree)malloc(sizeof(struct TreeNode));
	char d=getchar();
	if (d==' ' || d=='\n') return 0;
	Tree_Base->Element=d;
	Tree_Base->Left=BuildTree();
	Tree_Base->Right=BuildTree();
	return Tree_Base;
}

int Isomorphic(Tree T1, Tree T2)
{
	if (!T1 && !T2) return 1;
	if ((!T1 && T2) || (!T2 && T1)) return 0; 
	if (T1->Element!=T2->Element) return 0;
	int t1=Isomorphic(T1->Left,T2->Left),
		t2=Isomorphic(T1->Left,T2->Right),
		t3=Isomorphic(T1->Right,T2->Left),
		t4=Isomorphic(T1->Right,T2->Right);
	if ((t1 && t4) || (t2 && t3)) return 1;
	return 0;
}