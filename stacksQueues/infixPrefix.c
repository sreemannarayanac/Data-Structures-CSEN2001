#include<stdio.h>
#include<ctype.h>
char postfix[100];
int top = -1;

void push(char ch)
{
  postfix[++top] = ch;
}

char pop()
{
  if(top == -1)
    return -1;
  else
    return postfix[top--];
}

int priority(char ch)
{
  if(ch == '(')
    return 0;
  if(ch == '+' || ch == '-')
    return 1;
  if(ch == '*' || ch == '/')
    return 2;
  return 0;
}

int main()
{
  char infixExp[100];
  char *e, ch;
  printf("Enter infix expression: ");
  scanf("%s",infixExp);
  printf("\n");
  e = infixExp;

  printf("\nPostfix Expression of given infix expression is \n");
  while(*e != '\0')
  {
    if(isalnum(*e))
      printf("%c ",*e);
    else if(*e == '(')
      push(*e);
    else if(*e == ')')
    {
      while((ch = pop()) != '(')
        printf("%c ", ch);
    }
    else
    {
      while(priority(postfix[top]) >= priority(*e))
        printf("%c ",pop());
      push(*e);
    }
    e++;
  }
  
  while(top != -1)
  {
    printf("%c ",pop());
  }
  printf("\n");
  return 0;
}