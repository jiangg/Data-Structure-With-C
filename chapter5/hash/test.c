#include"hash.h"
#include<stdio.h>
#include<stdlib.h>

int main( )
{
      HashTable H;
      Position p;
      int i, k = 1, j = 0;

      H = create_table(13);
      for( i = 0; i < 400; i++, j += 71 )
      {
            insert(j, H);
      }

      for( i = 0, j = 0; i < 400; i++, j += 71 )
      {
            p = find(j, H);
            if( p == NULL )
                  printf("Error at  %d \n",j);
            else
                  printf("%6d",retrieve(p));
            if( k % 10 == 0 )
                  printf("\n");
            k++;
      }
      printf("\n");
      system("pause");
      return 0;

}