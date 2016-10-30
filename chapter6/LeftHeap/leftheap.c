#include "leftheap.h"
#include<stdlib.h>
#include"fatal.h"


struct TreeNode
{
      int npl;
      elementType item;
      PriorityQueue left;
      PriorityQueue right;
};

PriorityQueue initialize( )
{
      return NULL;
}

elementType find_min(PriorityQueue H)
{
      if(!empty(H))
            return H->item;
      Error("Priority queue is empty");
      return 0;
}

bool empty(PriorityQueue H)
{
      return H == NULL;
}

static void swapChild(PriorityQueue H)
{
      PriorityQueue tmp;

      tmp = H->left;
      H->left = H->right;
      H->right = tmp;
}

static PriorityQueue merge1(PriorityQueue H1, PriorityQueue H2)
{
      if(H1->left == NULL)
            H1->left = H2;
      else
      {
            H1->right = merge(H1->right, H2);
            if(H1->left->npl < H1->right->npl )
                  swapChild(H1);
            H1->npl = H1->right->npl + 1;
      }
      return H1;
}

PriorityQueue merge(PriorityQueue H1, PriorityQueue H2)
{
      if( H1 == NULL )
            return H2;
      if( H2 == NULL)
            return H1;
      if(H1->item < H2->item)
            return merge1(H1,H2);
      else
            return merge1(H2,H1);
}

PriorityQueue insert(elementType x, PriorityQueue H)
{
      PriorityQueue newnode;

      newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
      if(newnode == NULL)
            FatalError("Out of space");
      else
      {
            newnode->item = x;
            newnode->left= newnode->right = NULL;
            newnode->npl = 0;
            H = merge(newnode, H);
      }
      return H;
}

PriorityQueue delete_min(PriorityQueue H)
{
      PriorityQueue left;
      PriorityQueue right;

      if( empty(H) )
      {
            Error("Priority queue is empty");
            return H;
      }

      left = H->left;
      right = H->right;
      free(H);
      return merge(left,right);
}
