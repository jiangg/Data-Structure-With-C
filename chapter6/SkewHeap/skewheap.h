#pragma once
#ifndef SkewHeap_H
#define SkewHeap_H
#include<stdbool.h>

typedef int Type;

struct SkewNode;
typedef struct SkewNode *SkewHeap;
SkewHeap initialize();
Type find_min(SkewHeap H);
SkewHeap merge(SkewHeap H1, SkewHeap H2);
SkewHeap insert(Type x, SkewHeap H);
SkewHeap delete_min(SkewHeap H);
bool empty(SkewHeap H);
#endif // !SkewHeap_H
