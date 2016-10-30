#pragma once
#ifndef StackArray_H
#define StackArray_H
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define TopEmpty -1

typedef int elementType;

struct NodeArr;
typedef struct NodeArr *ArrStack;
typedef ArrStack PtrArrNode;

ArrStack createArrStack(int stackSize);
void arr_makeEmpty(ArrStack S);
bool arr_empty(ArrStack S);
void arr_push(elementType x, ArrStack S);
void arr_pop(ArrStack S);
elementType arr_top(ArrStack S);
void arr_destory(ArrStack S);
elementType arr_topAndPop(ArrStack S);

int posFixVal(char *postFix);
#endif // !StackArray_H
