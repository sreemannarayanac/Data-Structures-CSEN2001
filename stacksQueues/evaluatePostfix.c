#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define size 20

char pExpression[size];
int stack[size], top = -1;

void push(int n)
{
	if (top < size -1)
	{
		stack[++top] = n;
	}
	else
	{
		printf("Stack is full!\n");
		exit(-1);
	}
}

int pop()
{	
	int n;
	if (top > -1)
	{
		n = stack[top];
		stack[top--] = -1;
		return n;
	}
	else
	{
		printf("Stack is empty!\n");
		exit(-1);
	}
}

int getResult(char postfix[])
{
  int result;
  for(int i=0; postfix[i] != '\0'; i++)
  {
    char ch = postfix[i];

    if(isdigit(ch))
    {
      push(ch-'0');
    }
    else
    {
      int b = pop();
      int a = pop();
      
      switch(ch)
      {
        case '+': push(a+b);
            break;
        case '-': push(a-b);
            break;
        case '*': push(a*b);
            break;
        case '/': push(a/b);
            break;
        case '%': push(a%b);
            break;
      }
    }		
  }

  return pop();
}

int main(void)
{
	printf("\nEnter a postfix expression: ");
	scanf("%s",pExpression);

  int res = getResult(pExpression);
  printf("\nResult after evaluating postfix expression = %d\n", res);
}