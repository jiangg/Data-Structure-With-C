#pragma once
#ifndef LeftHeap_H
#define LeftHeap_H
#include<stdbool.h>

typedef int elementType;

struct TreeNode;
typedef struct TreeNode *PriorityQueue;

PriorityQueue initialize();
elementType find_min(PriorityQueue H);
bool empty(PriorityQueue H);
PriorityQueue merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue insert(elementType x, PriorityQueue H);
PriorityQueue delete_min(PriorityQueue H);

#endif // !LeftHeap_H
