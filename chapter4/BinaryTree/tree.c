#include "tree.h"
#include"fatal.h"


struct TreeNode
{
      element item;
      SearchTree left;
      SearchTree right;
};


SearchTree createTree( )
{
      SearchTree T = NULL;
      return T;
}

SearchTree makeEmpty(SearchTree T)
{
      if( T != NULL )
      {
            makeEmpty(T->right);
            makeEmpty(T->left);
            free(T);
      }
      return NULL;
}

Position find(element x, SearchTree T)
{
      if( T == NULL )
      {
            Error("error find ");
      }
      else if( x < T->item)
      {
            return find(x, T->left);
      }
      else if( x > T->item )
      {
            return find(x,T->right);
      }
      else
      {
            return T;
      }
}

Position find_max(SearchTree T)
{
      if( T != NULL )
      {
            while( T->right != NULL )
            {
                  T = T->right;
            }
     }
     return T;
}

Position find_min(SearchTree T)
{
      if( T != NULL )
      {
            while( T->left != NULL )
            {
                  T = T->left;
            }
      }
      return T;
}

SearchTree insert(element x, SearchTree T)
{
      Position p;

      if( T == NULL )
      {
            p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            if( p == NULL )
            {
                  FatalError("out of memory");
                  return NULL;
            }
            p->item = x;
            p->left = NULL;
            p->right = NULL;
            T = p;
      }
      else if( x < T->item )
      {
            T->left = insert(x,T->left);
      }
      else if( x > T->item )
      {
            T->right = insert(x,T->right);
      }
      return T;
}

SearchTree deleteElement(element x, SearchTree T)
{
      Position tmp;
      if( T == NULL )
      {
            Error("element not found");
      }
      else if( x < T->item )
      {
            T->left = deleteElement(x, T->left);
      }
      else if( x > T->item )
      {
            T->right = deleteElement(x,T->right);
      }
      else if( T->left && T->right )
      {
            tmp = find_min(T->right);
            T->item = tmp->item;
            T->right = deleteElement(tmp->item,T->right);
      }
      else
      {
            tmp = T;
            if(T->left == NULL)
                  T = T->right;
            else if(T->right == NULL)
                  T = T->left;
            free(tmp);
      }
      return T;
}

element retrieve(Position p)
{
      if(p)
            return p->item;
      return 0;
}

void preorder_tree(SearchTree T)
{
      if( T != NULL )
      {
            printf("%d ",T->item);
            preorder_tree(T->left);
            preorder_tree(T->right);
      }
}

void inorder_tree(SearchTree T)
{
      if( T != NULL )
      {
            inorder_tree(T->left);
            printf("%d ",T->item);
            inorder_tree(T->right);
      }
}

void postorder_tree(SearchTree T)
{
      if( T != NULL )
      {
            postorder_tree(T->left);
            postorder_tree(T->right);
            printf("%d ",T->item);
      }
}
