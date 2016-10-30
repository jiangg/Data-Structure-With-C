#include "hash.h"
#include<stdlib.h>
#include"fatal.h"


struct ListNode
{
      elementType item;
      Position next;
};

struct HashNode
{
      int table_size;
      Position *lists;
};

unsigned int Hash(elementType key, int tableSize)
{
      return key % tableSize;
}


HashTable create_table(int TableSize)
{
     HashTable H;
     int i;

     H = (struct HashNode*)malloc(sizeof(struct HashNode));
     if( H == NULL )
     {
           FatalError("Out of sapace");
     }
     H->table_size = TableSize;
     H->lists = (Position*)malloc(sizeof(Position) * H->table_size);
     if( H->lists == NULL )
     {
           FatalError("Out of space");
     }
     for( i = 0; i < H->table_size; i++ )
     {
           H->lists[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
           if( H->lists[i] == NULL )
           {
                 FatalError("Out of space");
           }
           H->lists[i]->next = NULL;
     }
     return H;
}

void destory_table(HashTable H)
{
      Position p, tmp;

      for( int i = 0; i < H->table_size; i++ )
      {
            tmp = H->lists[i];
            while( tmp != NULL )
            {
                  p = tmp->next;
                  free(tmp);
                  tmp = p;
            }
      }
      free(H->lists);
      free(H);
}

Position find(elementType key, HashTable H)
{
      Position pos, p;

      pos = H->lists[Hash(key,H->table_size)];
      p = pos->next;
      while( p != NULL && p->item != key )
      {
            p = p->next;
      }
      return p;
}

void insert(elementType key, HashTable H)
{
      Position p, pos, newnode;

      pos = find(key, H);
      if( pos == NULL )
      {
            newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
            if( newnode == NULL )
            {
                  FatalError("Out of space");
            }
            else
            {
                  newnode->item = key;
                  p = H->lists[Hash(key,H->table_size)];
                  newnode->next = p->next;
                  p->next = newnode;
            }
      }
}

elementType retrieve(Position p)
{
      return p->item;
}
