#include"leftheap.h"
#include<stdio.h>
#include<stdlib.h>

int main( )
{
      PriorityQueue H;
      int i, j = 0;

      H = initialize();
      for(i = 0; i < 1000; i++, j = (j + 71)%1000)
            H = insert(j, H);
      j = 1;
      while( !empty(H) )
      {
            printf("%6d",find_min(H));
            H = delete_min(H);
            if(j % 10 == 0)
                  printf("\n");
            j++;
      }
      printf("Done....\n");
      system("pause");
      return 0;

}