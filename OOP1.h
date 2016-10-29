#include <stdio.h>

#ifndef
#define OOP1_H_

struct Node
{
	enum Data_Type pType;
	void *pData;
	struct Node *pNext;
};

struct Node* Create();

void Destruct(struct Node *);

struct Node* Output(struct Node *);

struct Node* Insert_At_Front(struct Node *, struct Node *);

struct Node* Insert_At_End(struct Node *, struct Node *);

struct Node* Insert_At_Middle(struct Node *, struct Node *, int (*)(struct Node*, struct Node*));

struct Node* Delete_At_Front(struct Node *);

struct Node* Delete_At_End(struct Node *);

struct Node* Delete_At_Middle(struct Node *, int (*)(struct Node*));

struct Node* Reverse(struct Node *);

struct Node* Merge(struct Node *, struct Node *);

#endif