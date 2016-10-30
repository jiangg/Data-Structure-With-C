#include "binomial.h"
#include"fatal.h"

typedef struct BinNode *Position;

struct BinNode
{
      ElementType element;
      Position left;               // 最左儿子
      Position nextSibling;         // 兄弟节点
};

struct Collection
{
      int currentSize;
      BinTree TheTrees[MaxTrees];
};

BinQueue initialize( )
{
      BinQueue H;
      int i;

      H =  (struct Collection*)malloc(sizeof(struct Collection));
      if(H == NULL)
            FatalError("Out of space");
      H->currentSize = 0;
      for(i = 0; i < MaxTrees; i++)
            H->TheTrees[i] = NULL;
      return H;
}

static void destoryTree(BinTree T)
{
      if( T != NULL )
      {
            destoryTree(T->left);
            destoryTree(T->nextSibling);
            free(T);
      }
}

void destory(BinQueue H)
{
      int i;

      for(i = 0; i < MaxTrees; i++)
            destoryTree(H->TheTrees[i]);
}

BinQueue make_empty(BinQueue H)
{
      int i;

      destory(H);
      for(i = 0; i <MaxTrees; i++)
            H->TheTrees[i] = NULL;
      H->currentSize = 0;
      return H;
}

BinQueue insert(ElementType item, BinQueue H)
{
      BinTree newNode;
      BinQueue oneItem;

      newNode = (struct BinNode*)malloc(sizeof(struct BinNode));
      if(newNode == NULL)
            FatalError("Out of space");
      newNode->left = newNode->nextSibling = NULL;
      newNode->element = item;

      oneItem = initialize();
      oneItem->currentSize = 1;
      oneItem->TheTrees[0] = newNode;
      H = merge(H, oneItem);
      return H;
}

ElementType delete_min(BinQueue H)
{
      int i, j;
      int minTree = 0;
      BinQueue deleteQueue;
      Position deleteTree , oldRoot;
      ElementType MinItem;

      if( empty(H) )
      {
            Error("Empty binomial queue");
            return  -Infinity;
      }
      MinItem = Infinity;
      for( i = 0; i < MaxTrees; i++ )
      {
            if( H->TheTrees[i] != NULL && H->TheTrees[i]->element < MinItem )
            {
                  MinItem = H->TheTrees[i]->element;
                  minTree = i;
            }
      }
      deleteTree = H->TheTrees[minTree];
      oldRoot = deleteTree;
      deleteTree = deleteTree->left;
      free(oldRoot);

      deleteQueue = initialize();
      deleteQueue->currentSize = (i << minTree) - 1;
      for( j = minTree - 1; j >= 0; j-- )
      {
            deleteQueue->TheTrees[j] = deleteTree;
            deleteTree = deleteTree->nextSibling;
            deleteQueue->TheTrees[j]->nextSibling = NULL;
      }
      H->TheTrees[minTree] = NULL;
      H->currentSize -= deleteQueue->currentSize + 1;
      merge(H, deleteQueue);
      return MinItem;
}

BinTree combine_trees(BinTree T1, BinTree T2)
{
      if(T1->element > T2->element)
            return combine_trees(T2,T1);
      T2->nextSibling = T1->left;
      T1->left = T2;
      return T1;
}

BinQueue merge(BinQueue H1, BinQueue H2)
{
      BinTree T1, T2, carry = NULL;
      int i, j;

      if(H1->currentSize + H2->currentSize > Capacity)
            Error("Merge would excess capacity");
      H1->currentSize += H2->currentSize;
      for( i = 0, j = 1; j <= H1->currentSize; i++, j *= 2 )
      {
            T1 = H1->TheTrees[i];
            T2 = H2->TheTrees[i];
           if( T1 == NULL && T2 == NULL && carry == NULL  )
            {
                  ;
            }
            else if( T1 != NULL && T2 == NULL && carry == NULL )
            {
                  ;
            }
            else if( T1 == NULL && carry == NULL && T2 != NULL )
            {
                  H1->TheTrees[i] = T2;
                  H2->TheTrees[i] = NULL;
            }
            else if( T1 == NULL && T2 == NULL && carry != NULL )
            {
                  H1->TheTrees[i] = carry;
                  carry = NULL;
            }
            else if( T1 != NULL && T2 != NULL && carry == NULL )
            {
                  carry = combine_trees(T1,T2);
                  H1->TheTrees[i] = H2->TheTrees[i] = NULL;
            }
            else if( T1 != NULL && carry != NULL && T2 == NULL )
            {
                  carry = combine_trees(T1,carry);
                  H1->TheTrees[i] = NULL;
            }
            else if( T1 == NULL && T2 != NULL && carry != NULL )
            {
                  carry = combine_trees(T2,carry);
                  H2->TheTrees[i] = NULL;
            }
            else
            {
                  if( T1 != NULL && T2 != NULL && carry != NULL )
                  {
                        H1->TheTrees[i] = carry;
                        carry = combine_trees(T1,T2);
                        H2->TheTrees[i] = NULL;
                  }
            }
            /*switch( !!T1 + 2 * !!T2 + 4 * !!carry )
            {
                  case 0:
                        break;
                  case 1:
                        break;
                  case 2:
                        H1->TheTrees[i] = T2;
                        H2->TheTrees[i] = NULL;
                        break;
                  case 4:
                        H1->TheTrees[i] = carry;
                        carry = NULL;
                        break;
                  case 3:
                        carry = combine_trees(T1,T2);
                        H1->TheTrees[i] = H2->TheTrees[i] = NULL;
                        break;
                  case 5:
                        carry = combine_trees(T1, carry);
                        H1->TheTrees[i] = NULL;
                        break;
                  case 6:
                        carry = combine_trees(T2,carry);
                        H2->TheTrees[i] = NULL;
                        break;
                  case 7:
                        H1->TheTrees[i] = carry;
                        carry = combine_trees(T1,T2);
                        H2->TheTrees[i] = NULL;
                        break;
            }*/
      }
      return H1;
}

ElementType find_min(BinQueue H)
{
      int i;
      ElementType minItem = Infinity;

      if( empty(H) )
      {
            Error("Empty binomial queue");
            return 0;
      }
      for( i = 0; i < MaxTrees; i++ )
      {
            if(H->TheTrees[i] && H->TheTrees[i]->element < minItem)
                  minItem = H->TheTrees[i]->element;
      }
      return minItem;
}

bool empty(BinQueue H)
{
      return H->currentSize == 0;
}

bool full(BinQueue H)
{
      return H->currentSize == Capacity;
}
