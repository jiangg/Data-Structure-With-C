#pragma once
#ifndef HashQuad_H
#define HashQuad_H

typedef int elementType;
typedef unsigned int index, Position;

struct HashNode;
typedef struct HashNode *HashTable;

HashTable create_table(int tablesize);
void destory(HashTable H);
index find(elementType key, HashTable H);
void insert(elementType key, HashTable H);
elementType retrieve(Position p, HashTable H);
HashTable rehash(HashTable H);


#endif // !HashQuad_H
