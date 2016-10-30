#include"skewheap.h"
#include<stdio.h>
#include<stdlib.h>

int main( )
{
      SkewHeap H;
      int i, j = 0;

      H = initialize();
      for( i = 0, j = 1000 / 2; i < 1000; i++, j = ( j + 17 ) % 1000 )
      {
            H = insert(j, H);
      }
      while( !empty(H) )
      {
            printf("%8d",find_min(H));
            H = delete_min(H);
      }
      printf("\n");
      system("pause");
      return 0;
}