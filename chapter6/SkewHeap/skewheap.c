#include "skewheap.h"
#include<stdlib.h>
#include"fatal.h"

struct SkewNode
{
      Type item;
      SkewHeap left;
      SkewHeap right;
};

static void SwapChild(SkewHeap H)
{
      SkewHeap tmp;
      
      tmp = H->right;
      H->right = H->left;
      H->left = tmp;
}

SkewHeap initialize( )
{
      return NULL;
}

Type find_min(SkewHeap H)
{
      if(!empty(H))
            return H->item;
}

SkewHeap merge1(SkewHeap H1, SkewHeap H2)
{
      if(H1 == NULL)
            H1->left = H2;
      else
      {
            H1->right = merge(H1->right, H2);
            SwapChild(H1);
      }
      return H1;
}
SkewHeap merge(SkewHeap H1, SkewHeap H2)
{
      if(H1 == NULL)
            return H2;
      if(H2 == NULL)
            return H1;
      if(H1->item < H2->item)
            return merge1(H1,H2);
      else
            return merge1(H2,H1);
}

SkewHeap insert(Type x, SkewHeap H)
{
      SkewHeap newnode ;

      newnode = (struct SkewNode*)malloc(sizeof(struct SkewNode));
      if(newnode == NULL)
            FatalError("Out of space");
      else
      {
            newnode->item = x;
            newnode->right = newnode->left = NULL;
            H = merge(newnode, H);
      }
      return H;
}

SkewHeap delete_min(SkewHeap H)
{
      SkewHeap left, right;
      if(empty(H))
            return NULL;
      else
      {
            left = H->left;
            right = H->right;
            free(H);
            return merge(left,right);
      }
}

bool empty(SkewHeap H)
{
      return H == NULL;
}
