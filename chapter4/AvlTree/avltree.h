#pragma once
#ifndef AvlTree_H
#define AvlTree_H
#include<stdlib.h>
#include<stdio.h>


struct AvlNode;
typedef int element;
typedef struct AvlNode *AvlTree, *Position;

AvlTree createTree();
Position find(int x, AvlTree T);
Position find_min(AvlTree T);
Position find_max(AvlTree T);
AvlTree  insert(element x, AvlTree T);
AvlTree deleteElement(element x, AvlTree T);
element retrieve(Position p);
void destory_tree(AvlTree T);

void preorder_tree(AvlTree T);
void inorder_tree(AvlTree T);
void postorder_tree(AvlTree T);
#endif // !AvlTree_H
