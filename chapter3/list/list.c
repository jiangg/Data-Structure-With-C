#include "list.h"
#include"fata.h"

struct Node
{
      elementType item;
      Position next;
};

List makeEmpty(List L)
{
      if(L != NULL)
            deleteList(L);
      L = (struct Node*)malloc(sizeof(struct Node));
      if( L == NULL )
      {
            FatalError("Out of memory");
            return NULL;
      }
      L->next = NULL;
      return L;
}

List createList( )
{
      List L ;
      L = (struct Node*)malloc(sizeof(struct Node));
      if( L == NULL )
      {
            FatalError("Out of memory");
      }
      L->next = NULL;
      return L;
}

bool empty(List L)
{
      return L->next == NULL;
}

bool last(List p)
{
      return p->next == NULL;
}

Position find(elementType x, List L)
{
      Position p;

      p = L->next;
      while(p != NULL && p->item != x)
            p = p->next;
      return p;
}

void deleteElement(elementType x, List L)
{
      Position p , tmp;
      p = findPrevious(x,L);
      if( !last(L) )
      {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
      }
}

Position findPrevious(elementType x, List L)
{
      Position p;
      p = L;
      while(p != NULL && p->next->item != x)
            p = p->next;
      return p;
}

void insert(elementType x, List L, Position p)
{
      Position tmp;
      tmp = (struct Node*)malloc(sizeof(struct Node));
      if( tmp == NULL )
      {
            FatalError("Out of memory");
      }
      tmp->item = x;
      tmp->next = p->next;
      p->next = tmp;
}

void deleteList(List L)
{
      Position tmp, p;
      p = L->next;
      while( p != NULL )
      {
            tmp = p->next;
            free(p);
            p = tmp;
      }
}

Position header(List L)
{
      return L;
}

Position first(List L)
{
      return L->next;
}

Position advance(Position p)
{
      return p->next;
}

elementType retrieve(Position p)
{
      return p->item;
}


void printList(const List L)
{
      Position p = header(L);
      if( empty(L) )
      {
            printf("Empty list \n");
      }
      else
      {
            do
            {
                  p = advance(p);
                  printf("%3d",retrieve(p));
            }while(!last(p));
            printf("\n");
      }
}


// 链表的并集
List list_union(List L1, List L2)
{
      List new_list;
      Position p1, p2, p;

      new_list = (struct Node*)malloc(sizeof(struct Node));
      if( new_list == NULL )
      {
            FatalError("out of memory");
      }
      new_list->next = NULL;
      p1 = advance(L1);
      p2 = advance(L2);
      p = new_list;

      elementType insertElem;
      while( p1 != NULL && p2 != NULL )
      {
            if( p1->item < p2->item )
            {
                  insertElem = p1->item;
                  p1 = advance(p1);
            }
            else if( p1->item > p2->item )
            {
                  insertElem = p2->item;
                  p2 = advance(p2);
            }
            else
            {
                  insertElem = p1->item;
                  p1 = advance(p1);
                  p2 = advance(p2);
            }
            insert(insertElem, new_list, p);
            p = advance(p);
      }
      while( p1 != NULL )
      {
            insertElem = retrieve(p1);
            insert(insertElem, new_list,p);
            p1 = advance(p1);
            p = advance(p);
      }
      while( p2 != NULL )
      {
            insertElem = retrieve(p2);
            insert(insertElem,new_list,p);
            p2 = advance(p2);
            p = advance(p);
      }
      return new_list;
}

// 链表的交集

List intersect(List L1, List L2)
{
      List new_list;
      Position p1, p2, p;
      elementType insertElem;

      new_list = (struct Node*)malloc(sizeof(struct Node));
      if( new_list == NULL )
      {
            FatalError("Out of memory");
      }
      new_list->next = NULL;
      p = new_list;
      p1 = advance(L1);
      p2 = advance(L2);

      while( p1 != NULL && p2 != NULL )
      {
            if( p1->item == p2->item )
            {
                  insertElem = p1->item;
                  insert(insertElem, new_list, p);
                  p = advance(p);
            }
            p1 = advance(p1);
            p2 = advance(p2);
      }
      return new_list;

}


