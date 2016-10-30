#include"avltree.h"
#include<stdio.h>
#include<stdlib.h>

int main( )
{
      AvlTree T = createTree();
      Position p;
      int j[] = {3,21,51,78,45,12,15,98,97,95,92,94,90,81,87,82,86,83,74,75,76,70,64,68,67,66,63,50,10};
      
      for( int i = 0; i < 29; i++ )
      {
            T = insert(j[i],T);
      }
      for( int i = 0; i < 29; i++ )
      {
            p = find(j[i], T);
            if( p == NULL )
            {
                  printf("Nodt find the %d \n", j[i]);
            }
            else
            {
                  printf("%d ",retrieve(p));
            }
      }
      printf("\n");
      printf("Min is %d  Max is %d \n",retrieve(find_min(T)), retrieve(find_max(T)));

      printf("前序遍历: ");
      preorder_tree(T);
      printf("\n");
      printf("中序遍历: ");
      inorder_tree(T);
      printf("\n");
      printf("后序遍历: ");
      postorder_tree(T);
      printf("\n");
      system("pause");
      return 0;
}