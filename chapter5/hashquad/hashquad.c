#include "hashquad.h"
#include"fatal.h"
#include<stdlib.h>


enum KindOfEntry
{
      legitimate, empty, deleted
};

struct Node
{
      elementType element;
      enum KindOfEntry info;
};

struct HashNode
{
      int table_size;
      struct Node *theCells;
};

index Hash(elementType key, int tableSize)
{
      return key % tableSize;
}

HashTable create_table(int tableSize)
{
      HashTable H ;
      int i;

      H = (struct HashNode*)malloc(sizeof(struct HashNode));
      if( H == NULL )
      {
            FatalError("out of space");
      }
      H->table_size = tableSize;
      H->theCells = (struct Node*)malloc(sizeof(struct Node)*H->table_size);
      if( H->theCells == NULL )
      {
            FatalError("Out of space");
      }

      for(i = 0; i < H->table_size; i++)
            H->theCells[i].info = empty;
      return H;
}

void destory(HashTable H)
{
      free(H->theCells);
      free(H);
}

index find(elementType key, HashTable H)
{
      Position currentPos;
      int collisionNum = 0;

      currentPos = Hash(key, H->table_size);
      while( H->theCells[currentPos].info != empty && H->theCells[currentPos].element != key )
      {
            currentPos += 2 * ++collisionNum - 1;
            if(currentPos >= H->table_size)
                  currentPos -= H->table_size;
      }
      return currentPos;
}

void insert(elementType key, HashTable H)
{
      Position pos;

      pos = find(key, H);
      if( H->theCells[pos].info != legitimate )
      {
            H->theCells[pos].info = legitimate;
            H->theCells[pos].element = key;
      }
}

elementType retrieve(Position p, HashTable H)
{
      return H->theCells[p].element;
}

HashTable rehash(HashTable H)
{
      int i, oldsize;
      struct Node *oldcells;

      oldcells = H->theCells;
      oldsize = H->table_size;

      H = create_table(2 * H->table_size);
      for( i = 0; i < oldsize; i++ )
      {
            if(oldcells[i].info == legitimate)
                  insert(oldcells[i].element,H);
      }
      free(oldcells);
      return H;
}
