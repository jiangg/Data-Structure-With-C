#include "avltree.h"
#include"fatal.h"

static Position singleRotate_left(Position k1);
static Position singleRotate_right(Position k1);
static Position doubleRotate_left(Position k1);
static Position doubleRotate_right(Position k1);

struct AvlNode
{
      element item;
      int height;
      AvlTree left;
      AvlTree right;
};

static int Height(Position p)
{
      if(p == NULL)
            return -1;
      else
            return p->height;
}

static Position singleRotate_left(Position k1)
{
      Position k2;

      k2 = k1->left;
      k1->left = k2->right;
      k2->right = k1;

      k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
      k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
      return k2;
}

// 右单旋转
static Position singleRotate_right(Position k1)
{
      Position k2;

      k2 = k1->right;
      k1->right = k2->left;
      k2->left = k1;

      k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
      k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
      return k2;
}

// 左 -- 右双旋转
static Position doubleRotate_left(Position k1)
{
      k1->left = singleRotate_right(k1->left);
      k1 = singleRotate_left(k1);
      return k1;
}

// 右 -- 左 双旋转
static Position doubleRotate_right(Position k1)
{
      k1->right = singleRotate_left(k1->right);
      k1 = singleRotate_right(k1);
      return k1;
}

static Max(int lhs, int rhs)
{
      return lhs > rhs ? lhs : rhs;
}

AvlTree createTree( )
{
      AvlTree T = NULL;
      return T;
}

Position find(int x, AvlTree T)
{
      if( T == NULL )
      {
            return NULL;
      }

      if( x < T->item )
      {
            return find(x, T->left);
      }
      else if( x > T->item )
      {
            return find(x, T->right);
      }
      else
      {
            return T;
      }
}

Position find_min(AvlTree T)
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

Position find_max(AvlTree T)
{
      if( T != NULL )
      {
            while(T->right != NULL)
                  T = T->right;
      }
      return T;
}

AvlTree insert(element x, AvlTree T)
{
      if( T == NULL )
      {
            T = (struct AvlNode*)malloc(sizeof(struct AvlNode));
            if( T == NULL )
            {
                  FatalError("out of space");
            }
            else
            {
                  T->item = x;
                  T->height = 0;
                  T->left = T->right = NULL;
            }
      }
      else if( x < T->item )
      {
            T->left = insert(x, T->left);
            if( Height(T->left) - Height(T->right) == 2 )
            {
                  if(x < T->left->item)
                        T = singleRotate_left(T);
                  else
                        T = doubleRotate_left(T);
            }
      }
      else if( x > T->item )
      {
            T->right = insert(x, T->right);
            if( Height(T->left) - Height(T->right) == 2 )
            {
                  if(x > T->right->item)
                        T = singleRotate_right(T);
                  else 
                        T = doubleRotate_right(T);
            }
      }

      T->height = Max(Height(T->right), Height(T->left)) + 1;
      return T;
}

AvlTree deleteElement(element x, AvlTree T)
{
      return NULL;
}

element retrieve(Position p)
{
      return p->item;
}



void destory_tree(AvlTree T)
{
}

void preorder_tree(AvlTree T)
{
      if( T != NULL )
      {
            printf("%d ",T->item,T->height);
            preorder_tree(T->left);
            preorder_tree(T->right);

      }
}

void inorder_tree(AvlTree T)
{
      if( T != NULL )
      {
            inorder_tree(T->left);
            printf("%d ",T->item);
            inorder_tree(T->right);
      }
}

void postorder_tree(AvlTree T)
{
      if( T != NULL )
      {
            postorder_tree(T->left);
            postorder_tree(T->right);
            printf("%d ",T->item);
      }
}
