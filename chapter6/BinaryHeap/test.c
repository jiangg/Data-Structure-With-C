#include"binaryheap.h"
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 1000

int main( )
{
      PriorityQueue H;
      int i, j;

      H = initialize(MaxSize);
      for(i = 0, j = MaxSize /2; i < MaxSize; i++, j = (j + 71)% MaxSize)
            insert(j, H);
      j = 1;
      while( !empty(H) )
      {
            printf("%6d",find_min(H));
            deleteMin(H);
            if(j % 10 == 0)
                  printf("\n");
            j++;
      }
      printf("Done...\n");
      system("pause");
      return 0;
}