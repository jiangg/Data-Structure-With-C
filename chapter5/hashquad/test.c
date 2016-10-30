#include<stdio.h>
#include"hashquad.h"
#include<stdlib.h>


int main( )
{
      HashTable H;
      Position p;
      int currentSize = 73;
      int i, j = 0;

      H = create_table(73);
      for( i = 0; i < 400; i++, j += 71 )
      {
            if( i > currentSize / 2 )
            {
                  H = rehash(H);
                  printf("Rehashing......\n");
                  currentSize *= 2;
            }
            insert(j, H);
      }
      int  k = 1;
      for( i = 0, j = 0; i < 400; i++, j += 71 )
      {
            p = find(j, H);
            if( retrieve(p, H) != j )
            {
                  printf("Error at %d \n",j);
            }
            else
            {
                  printf("%8d",retrieve(p, H));
            }
            if( k % 10 == 0 )
            {
                  printf("\n");
            }
            k++;
      }
      printf("\n");
      destory(H);
      system("pause");
      return 0;
}