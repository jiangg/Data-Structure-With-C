#pragma once

/****************************************************************
			队列的数组实现
*****************************************************************/
typedef int ElementType;
#ifndef Queue_H

struct QueueRecord;
typedef struct QueueRecord *Queue;

int isEmpty(Queue Q);
int isFull(Queue Q);
Queue createQueue(int MaxElements);
void disposeQueue(Queue Q);
void makeEmpty(Queue Q);
void enQueue(ElementType x, Queue Q);
ElementType front(Queue Q);
void deQueue(Queue Q);
ElementType frontAndDequeue(Queue Q);

#endif // !Queue_H
