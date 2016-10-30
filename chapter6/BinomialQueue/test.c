#include<stdlib.h>
#include<stdio.h>
#include"binomial.h"
#define MaxSize 12000

int main( )
{
      BinQueue H;
      int i, j;
      ElementType anitem;

     H = initialize();
      for( i = 0, j = MaxSize / 2; i < MaxSize; i++, j = ( j + 71 ) % MaxSize )
      {
            H = insert(j, H);
      }
      j = 0;
      if( empty(H) )
      {
            system("pause");
            return 0;
      }
      i = 1;
      while( !empty(H) )
      {
           j = find_min(H);
           printf("%8d",j);
           delete_min(H);
           if(i % 20==0)
                  printf("\n");
            i++;
      }
      printf("Done....\n");
      system("pause");
      return 0;
}

