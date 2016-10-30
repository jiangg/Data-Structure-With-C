#include "pairheap.h"
#include"fatal.h"
#include<stdlib.h>

struct PairNode
{
      ElementType element;
      Position left_child;
      Position next_silbling;
      Position prev;
};

#define MaxSiblings 1000

Position compareAndLink(Position first,Position second);
PairHeap combineSiblings(Position firstSibling);


PairHeap initialize( )
{
      return NULL;
}

void destory(PairHeap H)
{
      make_empty(H);
}

PairHeap make_empty(PairHeap H)
{
      if( H != NULL )
      {
            make_empty(H->left_child);
            make_empty(H->next_silbling);
            free(H);
      }
      return NULL;
}

PairHeap insert(ElementType item, PairHeap H, Position * Loc)
{
      Position newNode;

      newNode = (struct PairNode*)malloc(sizeof(struct PairNode));
      if(newNode == NULL)
            FatalError("Out of space");
      newNode->element = item;
      newNode->left_child = newNode->next_silbling = NULL;
      newNode->prev = NULL;

      *Loc = newNode;
      if(H == NULL)
            return newNode;
      else
            return compareAndLink(H, newNode);
}

ElementType delete_min(ElementType * MinItem, PairHeap H)
{
      Position newroot = NULL;

      if(empty(H))
            Error("Pairing heap is empty");
      else
      {
            *MinItem = H->element;
            if(H->left_child != NULL)
                  newroot = combineSiblings(H->left_child);
            free(H);
       }
       return newroot;
}

ElementType find_min(PairHeap H)
{
      if(!empty(H))
            return H->element;
      Error("Priority Queue is empty");
      return 0;
}

PairHeap decrease_key(Position p, ElementType NewNal, PairHeap H)
{
      if(NewNal < 0)
            Error("DecreaseKey called with nagative Delta");
      p->element -= NewNal;
      if(p == H)
            return H;

      if(p->next_silbling != NULL)
            p->next_silbling->prev = p->prev;
      if(p->prev->left_child == p)
            p->prev->left_child = p->next_silbling;
      else
            p->prev->next_silbling = p->next_silbling;
      p->next_silbling = NULL;
      return compareAndLink(H, p);
}

bool empty(PairHeap H)
{
      return H == NULL;
}

bool full(PairHeap H)
{
      return false ;  // never full 
}

Position compareAndLink(Position first, Position second)
{
      if(second == NULL)
            return first;
      else if( first->element <= second->element )
      {
            second->prev = first;
            first->next_silbling = second->next_silbling;
            if(first->next_silbling != NULL)
                  first->next_silbling->prev = first;
            second->next_silbling = first->left_child;
            if(second->next_silbling != NULL)
                  second->next_silbling->prev = second;
            first->left_child = second;
            return first;
      }
      else
      {
            second->prev = first->prev;
            first->prev = second;
            first->next_silbling = second->left_child;
            if(first->next_silbling != NULL)
                  first->next_silbling->prev = first;
            second->left_child = first;
            return second;
      }
}

PairHeap combineSiblings(Position firstSibling)
{
      static Position TreeArray[MaxSiblings];
      int i, j, NumSiblings;

      if(firstSibling->next_silbling == NULL)
            return firstSibling;
      for( NumSiblings = 0; firstSibling != NULL; NumSiblings++ )
      {
            TreeArray[NumSiblings] = firstSibling;
            firstSibling->prev->next_silbling = NULL;
            firstSibling = firstSibling->next_silbling;
      }
      TreeArray[NumSiblings] = NULL;

      for( i = 0; i + 1 < NumSiblings; i += 2 )
      {
            TreeArray[i] = compareAndLink(TreeArray[i], TreeArray[i + 1]);
      }
      j = j - 2;
      if(j == NumSiblings - 3)
            TreeArray[j] = compareAndLink(TreeArray[j], TreeArray[j + 2]);

      for( ; j >= 2; j += 2 )
      {
            TreeArray[j - 2] = compareAndLink(TreeArray[j - 2], TreeArray[j]);
      }
      return TreeArray[0];
}
