#pragma once
#ifndef Tree_H
#define Tree_H
#include<stdlib.h>
#include<stdio.h>

typedef int element;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree createTree( );
SearchTree makeEmpty(SearchTree T);
Position find(element x, SearchTree T);
Position find_max(SearchTree T);
Position find_min(SearchTree T);
SearchTree insert(element x, SearchTree T);
SearchTree deleteElement(element x, SearchTree T);
element retrieve(Position p);

void preorder_tree(SearchTree T);         // 前序遍历
void inorder_tree(SearchTree T);          // 中序遍历
void postorder_tree(SearchTree T);        // 后序遍历

#endif // !Tree_H

