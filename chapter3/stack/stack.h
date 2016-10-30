#pragma once
#ifndef Stack_H
#define Stack_H
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef int element;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

Stack createStack();
void disposeStack(Stack S);
void makeEmpty(Stack S);
bool empty(Stack S);
void push(element x, Stack S);
element top(Stack S);
void pop(Stack S);

// 后缀表达式
int posFixEval(char *postFix);
#endif // !Stack_H
