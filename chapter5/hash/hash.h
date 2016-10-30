#pragma once
#ifndef Hash_H
#define Hash_H

typedef int elementType;
struct ListNode;
typedef struct ListNode *Position;

struct HashNode;
typedef struct HashNode *HashTable;

HashTable create_table(int TableSize);
void destory_table(HashTable H);
Position find(elementType key, HashTable H);
void insert(elementType key, HashTable H);
elementType retrieve(Position p);
#endif // !Hash_H
