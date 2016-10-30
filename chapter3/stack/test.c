#include"stack.h"
#include"stackarr.h"
//#include<stdio.h>

int main( )
{
      char ch[] = "6 5 2 3 + 8 * + 3 + *";
      int n = posFixVal(ch);
      printf("%d\n",n);

      Stack S = createStack();
      for( int i = 0; i < 5000; i += 14 )
      {
            push(i, S);
      }
      for( int i = 4998; i >= 0; i -= 14 )
      {
            n = top(S);
            pop(S);
            if( n != i )
            {
                  printf("Error at %d ",i);
            }
      }

      system("pause");
      return 0;
}