#include <stdio.h>
#include <stdlib.h> 

typedef struct
{
	int h,m,s;
} time;

typedef struct
{
	char Plate[7];
	time Intime, Outtime, Duration;
} Car_Record;

typedef struct TRC
{
	time point;
	int dif;
	TRC *next;
} Time_Record;
typedef Time_Record *TRP;

int greater(time a, time b)
{
	if (a.h>b.h) return 1;
	if (a.m>b.m) return 1;
	if (a.s>b.s) return 1;
	return 0;
}

int compare1(void *a, void *b)
{
	return greater((Car_Record*)a->Duration,(Car_Record*)b->Duration);
}

int compare2(void *a, void *b)
{
	return greater((Car_Record*)a->Intime,(Car_Record*)b->Intime);
}
 
Car_Record Rec[10086];
int n_CarR, n_query;
TRP TrecStt;

int scanp(int i)
{
	scanf("%s",Rec[i].Plate);
	int 
	scanf("%d,%d,%d", )
}