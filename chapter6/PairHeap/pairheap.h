#pragma once
#ifndef PairHeap_H
#define PairHeap_H
#include<stdbool.h>

typedef int ElementType;

struct PairNode;
typedef struct PairNode *PairHeap;
typedef struct PairNode *Position;

PairHeap initialize();
void destory(PairHeap H);
PairHeap make_empty(PairHeap H);
PairHeap insert(ElementType item, PairHeap H, Position *Loc);
ElementType delete_min(ElementType *MinItem, PairHeap H);
ElementType find_min(PairHeap H);
PairHeap decrease_key(Position p, ElementType NewNal, PairHeap H);
bool empty(PairHeap H);
bool full(PairHeap H);
#endif // !PairHeap_H
