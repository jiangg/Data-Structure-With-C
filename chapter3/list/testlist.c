#include"list.h"

int main( )
{
      List L = makeEmpty(NULL);
      Position p = header(L);
      for( int i = 0; i < 5000; i += 41 )
      {
            insert(i,L,p);
            p = advance(p);
      }
      for( int i = 0; i < 5000; i += 41 )
      {
            p = find(i,L);
            if( retrieve(p) != i )
            {
                  printf("Error at %3d\n",i);
            }
            printf("%d ",retrieve(p));
      }
      printf("\n");
      makeEmpty(L);
      if( empty(L) )
      {
            printf("L is empty\n");
      }
      else
      {
            printf("L is not empty\n");
      }

      system("pause");
      return 0;

}