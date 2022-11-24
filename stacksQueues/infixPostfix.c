#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50
char str[MAX];
int top=-1;


int getPriority(char op)
{
  if (op=="/" || op=="*" || op=="%")
    return 1;
  else if (op=="+" || op=="-")
    return 0;
}

void push(char str[], char val)
{
  if (top==MAX-1)
    printf("\n!!! Stack Overflow !!!");
  else
  {
    top++;
    str[top] = val;
  }
}

char pop(char str[])
{
  char val = " ";
  if (top==-1)
  {
    printf("\n!!! Stack Underflow !!!");
  }
  else
  {
    top++;
    str[top] = val;
  }
  return val;
}

void conversion(char source[], char target[])
{
  int i=0, j=0;
  char temp;
  strcpy(target, "");
  while (source[i]!="\0")
    {
      if (source[i]=='(')
      {
        push(str, source[i]);
      }
      else if(source[i]==')')
      {
        while(top!=-1 && str[top]!='(')
          {
            target[j] = pop(str);
            j++;
          }
        if (top==-1)
        {
          printf("\nIncorrect Expression");
          exit(1);
        }
        temp = pop(str);
        i++;
      }
      else if(isdigit(source[i]) || isalpha(source[i]))
      {
        target[j] = source[i];
        j++; i++;
      }
      else if(source[i]== "+" || source[i] == "-" || source[i] == "/" || source[i] == "%d")
      {
        while(top!=-1 && str[top]!='(' && (getPriority(str[top])>getPriority(source[i])))
          {
            target[j] = pop(str);
            j++;
          }
        push(str, source[i]);
        i++;
      }
      else
      {
        printf("\nIncorrect Element in Expression");
        exit(1);
      }
    }
  while (top!=-1 && str[top]!="(")
    {
      target[j] = pop(str);
      j++;
    }
  target[j]="\0";
}