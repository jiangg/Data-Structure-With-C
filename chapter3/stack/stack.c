#include "stack.h"
#include"fatal.h"
#include<ctype.h>


bool isOperator(char ch);


struct Node
{
      element item;
      PtrToNode *next;
};

Stack createStack( )
{
      Stack S;

      S = (struct Node*)malloc(sizeof(struct Node));
      if( S == NULL )
      {
            FatalError("out of memory");
      }
      S->next = NULL;
      return S;
}

void disposeStack(Stack S)
{
      if( !empty(S) )
      {
            makeEmpty(S);
      }
      free(S);
}

void makeEmpty(Stack S)
{
      while( !empty(S) )
      {
            pop(S);
      }
}

bool empty(Stack S)
{
      return S->next == NULL;
}

void push(element x, Stack S)
{     
      PtrToNode tmp;

      tmp = (struct Node*)malloc(sizeof(struct Node));
      if( tmp == NULL )
      {
            FatalError("Out of memory");
      }
      tmp->item = x;
      tmp->next = S->next;
      S->next = tmp;
}

element top(Stack S)
{
      PtrToNode p = S->next;
      if( !empty(S) )
      {
            return p->item;
      }
      Error("top empty stack");
      return 0;
}

void pop(Stack S)
{
      PtrToNode tmp;
      if( !empty(S) )
      {
            tmp = S->next;
            S->next = tmp->next;
            free(tmp);
      }
      else
      {
            Error("pop empty stack");
            return ;
      }
}

bool isOperator(char ch)
{
      int i;
      char oper[] = "+-*/";
      for( i = 0; i < strlen(oper); i++ )
      {
            if(ch == oper[i])
                  return true;
      }
      return false;
}

int posFixEval(char *postFix)
{
      Stack S = createStack();
      char ch;
      int i, len,val;
      int op1, op2;
      len = strlen(postFix);

      for( i = 0; i <len; i++ )
      {
            ch = postFix[i];
            if( isOperator(ch) )
            {
                  op1 = top(S);
                  pop(S);
                  op2 = top(S);
                  pop(S);
                  switch( ch )
                  {
                        case '+':
                              val = op1 + op2;  break;
                        case '-':
                              val = op1 - op2;  break;
                        case '*':
                              val = op1 * op2;  break;
                        case '/':
                              val = op1 / op2;  break;
                        default:               
                              break;
                  }
                  push(val,S);
                  printf("%4d push\n",val);
            }
            else if( isspace(ch) )
            {
                  ;
            }
            else
            {
                  push(ch - '0',S);
                  printf("%4c push\n",ch);
            }
      }
      return top(S);
}
