#include "stackarr.h"
#include"fatal.h"
#include<string.h>
#include<ctype.h>


#define MinSize 0

struct NodeArr
{
      elementType *item;
      int capacity;
      int StackTop;
      PtrArrNode next;
};

ArrStack createArrStack(int stackSize )
{
      ArrStack S;

      if( stackSize < MinSize )
      {
            FatalError("stack size too small");
      }
      S = (struct NodeArr*)malloc(sizeof(struct NodeArr));
      if( S == NULL )
      {
            FatalError("out of memory");
      }
      S->item = (elementType*)malloc(sizeof(elementType)*stackSize);
      if( S->item == NULL )
      {
            FatalError("out of memory");
      }
      S->capacity = stackSize;
      S->StackTop = TopEmpty;
      return S;
}

void arr_makeEmpty(ArrStack S)
{
      S->StackTop = TopEmpty;
}

bool arr_empty(ArrStack S)
{
      return S->StackTop == TopEmpty;
}

void arr_push(elementType x, ArrStack S)
{
      if( S->StackTop + 1 < S->capacity )
      {
            S->item[++S->StackTop] = x;
      }
      else
      {
            FatalError("push full stack");
      }
}

void arr_pop(ArrStack S)
{
      if( arr_empty(S) )
      {
            FatalError("pop empty stack");
      }
      else
      {
            S->StackTop--;   
      }
}

elementType arr_top(ArrStack S)
{
      if( !arr_empty(S) )
      {
            return S->item[S->StackTop];
      }
      else
      {
            FatalError("top empty stack");
            return 0;
      }
}

void arr_destory(ArrStack S)
{
      if( S != NULL )
      {
            free(S->item);
            free(S);
     }
}

elementType arr_topAndPop(ArrStack S)
{
      if(!arr_empty(S))
            return S->item[S->StackTop--];
      Error("top and pop empty stack");
      return 0;
}

bool IsOperator(char ch)
{
      char oper[] = "+-*/";
      for( int i = 0; i < strlen(oper); i++ )
      {
            if(ch == oper[i])
                  return true;
      }
      return false;
}

int posFixVal(char * postFix)
{
      int i, len, op1, op2, val;
      char ch;
      ArrStack S;

      len = strlen(postFix);
      S = createArrStack(len);
     
      for( int i = 0; i < len; i++ )
      {
            ch = postFix[i];
            if( IsOperator(ch) )
            {
                  op1 = arr_topAndPop(S);
                  op2 = arr_topAndPop(S);
                  switch( ch )
                  {
                        case '+':
                              val = op1 + op2;
                              break;
                        case '-':
                              val = op1 - op2;
                              break;
                        case '*':
                              val = op1 * op2;
                              break;
                        case '/':
                              val = op1 / op2;
                              break;
                        default:
                              break;
                  }
                  arr_push(val, S);
            }
            else if( isspace(ch) )
            {
                  ;
            }
            else
            {
                  arr_push(ch-'0',S);
            }
      }
      return arr_top(S);
}
