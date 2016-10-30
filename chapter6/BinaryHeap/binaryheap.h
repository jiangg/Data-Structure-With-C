#pragma once
#ifndef BinaryHeap_H
#define BinaryHeap_H
#include<stdlib.h>
#include<stdbool.h>

typedef int elementType;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue initialize(int maxElements);
void destory(PriorityQueue H);
void make_empty(PriorityQueue H);
void insert(elementType x, PriorityQueue H);
elementType deleteMin(PriorityQueue H);
elementType find_min(PriorityQueue H);
bool empty(PriorityQueue H);
bool full(PriorityQueue H);


// BuildHeap
void buildHeap(int a[], int n);
#endif // !BinaryHeap_h
