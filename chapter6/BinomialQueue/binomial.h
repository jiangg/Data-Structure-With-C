#pragma once
#ifndef BinomialQueue_H
#define BionmialQueue_H
#include<stdbool.h>

typedef long ElementType;
#define Infinity 300000L
#define MaxTrees 14
#define Capacity 16383

struct BinNode;
typedef struct BinNode *BinTree;
struct Collection;
typedef struct Collection *BinQueue;

BinQueue initialize();
void destory(BinQueue H);
BinQueue make_empty(BinQueue H);
BinQueue insert(ElementType item, BinQueue H);
ElementType delete_min(BinQueue H);
BinQueue merge(BinQueue H1, BinQueue H2);
ElementType find_min(BinQueue H);
bool empty(BinQueue H);
bool full(BinQueue H);
#endif // !BinomialQueue_H
