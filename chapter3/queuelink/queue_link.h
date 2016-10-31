#pragma once
/*********************************************************
*                  队列的链表实现
*
*********************************************************/
typedef int Element;
#ifndef Queue_Link_H
#define Queue_Link_H

struct QueueLink;
typedef struct QueueLink *Queue;
struct QueueNode;
Queue CreateQueue();
int IsEmpty(Queue Q);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void EnQueue(Element x, Queue Q);
void DeQueue(Queue Q);
Element Front(Queue Q);
Element FrontAndDeQueue(Queue Q);

#endif // !Queue_Link_H
