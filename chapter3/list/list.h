#pragma once
#ifndef List_H
#define List_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int elementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List makeEmpty(List L);
List createList( );
bool empty(List L);
bool last(List L);
Position find(elementType x, List L);
void deleteElement(elementType x, List L);
Position findPrevious(elementType x, List L);
void insert(elementType x, List L, Position p);
void deleteList(List L);
Position header(List L);
Position first(List L);
Position advance(Position p);
elementType retrieve(Position p);
void printList(const List L);


List list_union(List L1, List L2);              // 链表的并集
List intersect(List L1, List L2);               // 链表的交集

#endif // !List_H


