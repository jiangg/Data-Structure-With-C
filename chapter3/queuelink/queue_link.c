#include "queue_link.h"
#include"fatal.h"
#include<stdlib.h>

/*
************************************************************
*
*	本程序中 QueueLink 的 Items 不带表头
*
************************************************************
*/

struct QueueNode
{
	Element item;
	struct QueueNode *next;
};

struct QueueLink
{
	int size;
	struct QueueNode *front, *rear;
};

Queue CreateQueue()
{
	Queue Q = malloc(sizeof(struct QueueLink));
	if (Q == NULL)
		FataError("Out of space");
	Q->size = 0;
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

int IsEmpty(Queue Q)
{
	return Q->rear == NULL;
}

void DisposeQueue(Queue Q)
{
	if (IsEmpty(Q))
	{
		free(Q);
	}
	else
	{
		MakeEmpty(Q);
		free(Q);
	}
}

void MakeEmpty(Queue Q)
{
	if (IsEmpty(Q))
		return;
	struct QueueNode *temp, *p;
	temp = Q->front;
	Q->front = NULL;
	Q->rear = NULL;
	while (temp != NULL)
	{
		p = temp->next;
		free(temp);
		temp = p;
	}
	Q->size = 0;
}

void EnQueue(Element x, Queue Q)
{
    struct QueueNode *temp;
    temp = malloc(sizeof(struct QueueNode));
    if (temp == NULL)
			FataError("Out of space");
    temp->item = x;
    temp->next = NULL;
	if (IsEmpty(Q))
	{
        Q->rear = temp;
        Q->front = temp;
	}
	else
    {
        Q->rear->next = temp;
        Q->rear = temp;
	}
	Q->size++;
}

void DeQueue(Queue Q)
{
	if (IsEmpty(Q))
		Error("Please Create A Queue");
	struct QueueNode *temp;
	temp = Q->front;
	Q->front = Q->front->next;
	free(temp);
	Q->size--;
    if (Q->size == 0)
    {
        Q->front = NULL;
        Q->rear = NULL;
    }
}

Element Front(Queue Q)
{
    if(IsEmpty(Q))
        return 0;
	Element x = Q->front->item;
	return x;
}

Element FrontAndDeQueue(Queue Q)
{
	if (IsEmpty(Q))
		return 0;
	Element x = Q->front->item;
	DeQueue(Q);
	return x;
}
