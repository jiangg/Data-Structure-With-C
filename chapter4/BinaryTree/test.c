#include"tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static int Max(int lhs, int rhs)
{
      return lhs > rhs ? lhs : rhs;
}

int main( )
{     
      SearchTree T;
      Position p;
      int i , j = 0;

      srand((unsigned int)time(NULL));
      T = createTree();
      for( i = 0; i < 50; i++ )
      {
            j = i + rand() % 100 + 1;
            T = insert(j, T);
      }
      printf("前序遍历: ");
      preorder_tree(T);
      printf("\n");
      printf("中序遍历: ");
      inorder_tree(T);
      printf("\n");
      printf("后序遍历: ");
      postorder_tree(T);
      printf("\n");
      printf("min is %d , max is %d\n",retrieve(find_min(T)), retrieve(find_max(T)));
      for( i = 0; i < 10; i++ )
      {
            printf("输入要删除的数字： ");
            scanf("%d",&j);
            T = deleteElement(j,T);
      }
      printf("前序遍历: ");
      preorder_tree(T);
      printf("\n");
      printf("中序遍历: ");
      inorder_tree(T);
      printf("\n");
      printf("后序遍历: ");
      postorder_tree(T);
      printf("\n");
      printf("min is %d , max is %d\n",retrieve(find_min(T)), retrieve(find_max(T)));

      printf("max = %d\n", Max(12,12));
      system("pause");
      return 0;
}