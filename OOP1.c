#include <stdio.h>
#include <stdlib.h>
enum Data_Type{_int, _long, _short, _float, _double, _char, _charpointer, _pointer}; /*����C�����޷�����ͬ�������ͻ�ϴ洢���ʶ������˱�ǩ*/

struct Node
{
	enum Data_Type pType; /*�������ͼ�¼�о� */
	void *pData; /*���� */
	struct Node *pNext; /*��һ�ڵ� */
};

struct Node* Create() /*��������ͷ������ֵΪ����ͷ */
{
	struct Node *NStart=(struct Node*)malloc(sizeof(struct Node*));
	return NStart;
}

void Destruct(struct Node *Start) /*�ݻ������ͷ�����ͷ�����ڴ�λ���˴�Ĭ�������ѿ� */
{
	free(Start);
	return;
}

struct Node* Output(struct Node *Start) /*��Բ�ͬ�������ͽ�����������ǲ�������ص�ָ�룬��Ϊ�޷���ָ֪������ͣ� */
{
	struct Node *temp=Start;
	while (temp)
	{
		switch(temp->pType)
		{
			case _int: case _long: case _short:
			printf("%d", *(int*)(temp->pData));
			break;
			case _float:
			printf("%f", *(float*)(temp->pData));
			break;
			case _double:
			printf("%lf",*(double*)(temp->pData));
			break;
			case _char:
			printf("%c", *(char*)(temp->pData));
			break;
			case _charpointer:
			printf("%s", (char*)(temp->pData));
			break;
			default:
			break;
		}
		printf(" "); 
		temp=temp->pNext;
	}
	return Start;
}

struct Node* Insert_At_Front(struct Node *Dest, struct Node *Start) /*������ͷ����׸�Ԫ�ؼ����ֳɵĽڵ�Ԫ�أ���������ͷ*/ 
{
	struct Node* Temp=Start->pNext;
	Dest->pNext=Temp;
	Start->pNext=Dest; 
	return Start;
}

struct Node* Insert_At_End(struct Node *Dest, struct Node *Start) /*������β�����ֳɵĽڵ�Ԫ�أ���������ͷ */
{
	struct Node *temp=Start->pNext, *temp2;
		while (temp) temp2=temp, temp=temp->pNext; 
	temp2->pNext=Dest;
	Dest->pNext=0;
	return Start;
}

struct Node* Insert_At_Middle(struct Node *Dest, struct Node *Start, int (*Compare)(struct Node*, struct Node*)) /*����������ĳһ�ȽϺ���������ֵΪint���ĵ�һ���ڵ�Ԫ�ز��룬������뵽��󣬷�������ͷ*/ 
{
	struct Node *temp=Start->pNext, *temp2;
	while (temp && !(*Compare)(temp,Dest)) temp2=temp, temp=temp->pNext; 
	temp2=temp->pNext;
	temp->pNext=Dest;
	Dest->pNext=temp2;
	return Start;
}

struct Node* Delete_At_Front(struct Node *Start) /*ɾȥ����ͷ֮��ĵ�һ���ڵ�Ԫ�أ���������ͷ */
{
	struct Node *temp=Start->pNext;
	Start->pNext=temp->pNext;
	free(temp);
	return Start;
}

struct Node* Delete_At_End(struct Node *Start) /*ɾȥ�������һ���ڵ�Ԫ�أ���������ͷ */
{
	struct Node *temp=Start->pNext, *temp2;
		while (temp) temp2=temp, temp=temp->pNext; 
	free(temp2->pNext);
	temp2->pNext=0;
	return Start;
}

struct Node* Delete_At_Middle(struct Node *Start, int (*Compare)(struct Node *)) /*ɾȥ���������������ĵ�һ��Ԫ�أ���������ͷ */
{
	struct Node *temp=Start->pNext, *temp2, *last;
	while (temp && !(*Compare)(temp)) temp2=temp, temp=temp->pNext; 
	if (temp) 
	{
		temp2->pNext=temp->pNext;
		free(temp);
	}
	return Start;
}

struct Node* Reverse(struct Node *Start) /*��ת������������ͷ */
{
	struct Node *temp=Start->pNext, *temp2, *last, *tempstart=temp;
	if (temp==0) return Start;
	while (temp)
	{
		last=temp;
		temp=temp2;
		if (temp==0) break;
		temp2=temp->pNext;
		temp->pNext=last;
	}
	Start->pNext=last;
	tempstart->pNext=0;
	return Start;
} 

struct Node* Merge(struct Node *Start1, struct Node *Start2) /*���ڶ�������ͷ���ڵ�������ڵ�һ������ͷ���ڵ������β�������ص�һ������ͷ */
{
	struct Node *temp=Start1->pNext;
	while (temp->pNext) temp=temp->pNext;
	temp->pNext=Start2->pNext;
	return Start1;
} 
