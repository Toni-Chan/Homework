#include <stdio.h>
#include <stdlib.h>
enum Data_Type{_int, _long, _short, _float, _double, _char, _charpointer, _pointer}; /*由于C语言无法处理不同数据类型混合存储，故而设置了标签*/

struct Node
{
	enum Data_Type pType; /*数据类型记录列举 */
	void *pData; /*内容 */
	struct Node *pNext; /*下一节点 */
};

struct Node* Create() /*建立链表头，返回值为链表头 */
{
	struct Node *NStart=(struct Node*)malloc(sizeof(struct Node*));
	return NStart;
}

void Destruct(struct Node *Start) /*摧毁链表，释放链表头所在内存位，此处默认链表已空 */
{
	free(Start);
	return;
}

struct Node* Output(struct Node *Start) /*针对不同数据类型进行输出，但是不输出记载的指针，因为无法得知指针的类型； */
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

struct Node* Insert_At_Front(struct Node *Dest, struct Node *Start) /*在链表头后的首个元素加入现成的节点元素，返回链表头*/ 
{
	struct Node* Temp=Start->pNext;
	Dest->pNext=Temp;
	Start->pNext=Dest; 
	return Start;
}

struct Node* Insert_At_End(struct Node *Dest, struct Node *Start) /*在链表尾加入现成的节点元素，返回链表头 */
{
	struct Node *temp=Start->pNext, *temp2;
		while (temp) temp2=temp, temp=temp->pNext; 
	temp2->pNext=Dest;
	Dest->pNext=0;
	return Start;
}

struct Node* Insert_At_Middle(struct Node *Dest, struct Node *Start, int (*Compare)(struct Node*, struct Node*)) /*在链表满足某一比较函数（返回值为int）的第一个节点元素插入，否则插入到最后，返回链表头*/ 
{
	struct Node *temp=Start->pNext, *temp2;
	while (temp && !(*Compare)(temp,Dest)) temp2=temp, temp=temp->pNext; 
	temp2=temp->pNext;
	temp->pNext=Dest;
	Dest->pNext=temp2;
	return Start;
}

struct Node* Delete_At_Front(struct Node *Start) /*删去链表头之后的第一个节点元素，返回链表头 */
{
	struct Node *temp=Start->pNext;
	Start->pNext=temp->pNext;
	free(temp);
	return Start;
}

struct Node* Delete_At_End(struct Node *Start) /*删去链表最后一个节点元素，返回链表头 */
{
	struct Node *temp=Start->pNext, *temp2;
		while (temp) temp2=temp, temp=temp->pNext; 
	free(temp2->pNext);
	temp2->pNext=0;
	return Start;
}

struct Node* Delete_At_Middle(struct Node *Start, int (*Compare)(struct Node *)) /*删去链表中满足条件的第一个元素，返回链表头 */
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

struct Node* Reverse(struct Node *Start) /*翻转链表，返回链表头 */
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

struct Node* Merge(struct Node *Start1, struct Node *Start2) /*将第二个链表头所在的链表接在第一个链表头所在的链表结尾，并返回第一个链表头 */
{
	struct Node *temp=Start1->pNext;
	while (temp->pNext) temp=temp->pNext;
	temp->pNext=Start2->pNext;
	return Start1;
} 
