#include <stdio.h>
#include <stdlib.h>

/*DFS*/

int map_register[105][100], map_weight[105], map_width[105];
int lcount,ncount,dest;
int box[1008],cdepth=1;

int compare(const void* i, const void* j)
{
	return map_weight[*(int*)i]<map_weight[*(int*)j];
}

void Input()
{
	int i,j,t;
	scanf("%d %d %d",&lcount,&ncount,&dest);
	for (i=0; i<lcount; i++) scanf("%d", &map_weight[i]);
	for (i=0; i<ncount; i++)
	{
		scanf("%d",&t);
		scanf("%d",&map_width[t]);
		for (j=0; j<map_width[t]; j++) scanf("%d",&map_register[t][j]);
		qsort(map_register[t],map_width[t],sizeof(int),compare);
	}
}

void DFS(int current,int node)
{
	if (current>dest) return;
	if (current==dest)
	{
		if (map_register[node][0]) return;
		int i;
		for (i = 0; i < cdepth; i++)
		{
			printf("%d", box[i]);
			if (i != cdepth - 1) printf(" ");
		}
		
		
		printf("\n");
		return;
	}
	int i;
	for (i=0; i<map_width[node]; i++)
	{
		box[cdepth]=map_weight[map_register[node][i]];
		cdepth++;
		DFS(current+box[cdepth-1],map_register[node][i]);
		cdepth--;
	}
	return;
}

int main()
{
	Input();
	box[0] = map_weight[0];
	DFS(map_weight[0],0);
	return 0;
}

