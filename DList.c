#include "DList.h"

LTNode*  ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);

	LTNode* tail = phead->prev;
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;

	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}

void ListPopBack(LTNode* phead)
{
	assert(phead);

	LTNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
}

void ListPushFront(LTNode* phead, LTDateType x);

void ListPopFront(LTNode* phead);