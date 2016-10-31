#include "queue.h"
#include"fatal.h"
#include<stdlib.h>

#define MinQueueSize 5

struct QueueRecord
{
	int capacity;
	int front;
	int rear;
	int size;
	ElementType *Array;
};

int isEmpty(Queue Q)
{
	return Q->size == 0;
}

int isFull(Queue Q)
{
	return Q->size == Q->capacity;
}

Queue createQueue(int MaxElements)
{
	Queue Q;
	if (MaxElements < MinQueueSize)
		Error("Queue size is too small");
	Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
		FataError("Out of space");
	Q->Array = malloc(sizeof(ElementType)* MaxElements);
	if (Q->Array == NULL)
		FataError("Out of space");
	Q->capacity = MaxElements;
	makeEmpty(Q);
	return Q;
}

void disposeQueue(Queue Q)
{
	if (Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}

void makeEmpty(Queue Q)
{
	Q->size = 0;
	Q->front = 1;
	Q->rear = 0;
}

static int Succ(int value, Queue Q)
{
	if (++value == Q->capacity)
		value = 0;
	return value;
}

void enQueue(ElementType x, Queue Q)
{
	if (isFull(Q))
		Error("Full queue");
	else
	{
		Q->size++;
		Q->rear = Succ(Q->rear, Q);
		Q->Array[Q->rear] = x;
	}
}

ElementType front(Queue Q)
{
	if (!isEmpty(Q))
		return Q->Array[Q->front];
	Error("Empty queue");
	return 0;
}

void deQueue(Queue Q)
{
	if (isEmpty(Q))
		Error("Empty queue");
	else
	{
		Q->size--;
		Q->front = Succ(Q->front, Q);//---------------------------------------------- ´ýÐø
	}
}

ElementType frontAndDequeue(Queue Q)
{
	ElementType x = 0;
	if (isEmpty(Q))
		Error("Empty queue");
	else
	{
		Q->size--;
		x = Q->Array[Q->front];
		Q->front = Succ(Q->front, Q);
	}
	return x;
}
