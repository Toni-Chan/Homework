#include<stdio.h>
#include<stdlib.h>

int TreeC[105],TreeCNew[105];
int conn[105][2];
int Midsq[105], Travsq[105]; 
int NNode; 

void CreateTree(int Pos) 
{
	int t;
	for (t = 0; t < NNode; t++)
		scanf("%d%d", &conn[t][0], &conn[t][1]);
}

void GenerateMidSq(int Pos)
{
	static int Midsq_n=0;
	if (conn[Pos][0]!=-1) GenerateMidSq(conn[Pos][0]);
	Midsq[Midsq_n++]=Pos;
	if (conn[Pos][1]!=-1) GenerateMidSq(conn[Pos][1]);
}

void GenerateTravSq()
{
	int Travsq_f=0,Travsq_b=0,temp;
	Travsq[Travsq_f++]=0;
	while(Travsq_b!=Travsq_f)
	{
		temp=Travsq[Travsq_b];
		if (conn[temp][0]!=-1) Travsq[Travsq_f++]=conn[temp][0];
		if (conn[temp][1]!=-1) Travsq[Travsq_f++]=conn[temp][1];
		Travsq_b++;
	}
	return;
}

int compare(const void *a, const void *b)
{
	if (*((int*)a) > *((int*)b)) return 1;
	if (*((int*)a) < *((int*)b)) return -1;
	return 0;
}

int main()
{
	scanf("%d",&NNode);
	CreateTree(0);
	int i;
	for (i=0; i<NNode; i++) scanf("%d", &TreeC[i]);
	qsort(TreeC,NNode,sizeof(int),compare);
	GenerateMidSq(0);
	GenerateTravSq();
	for (i=0; i<NNode; i++) 
		TreeCNew[Midsq[i]]=TreeC[i];
	for (i=0; i<NNode; i++)
	{
		printf("%d", TreeCNew[Travsq[i]]);
		if (i!=NNode-1) printf(" ");
	}
	return 0;
}