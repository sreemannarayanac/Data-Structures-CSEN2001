#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
char string[MAX];
int top = -1;

void push(char a)
{
  if (top==MAX-1)
  {
    printf("\n!!! Stack Overflow !!!");
    return;
  }
  string[++top] = a;
}

char pop()
{
  if (top==-1)
  {
    printf("\n!!! Stack Underflow !!!");
    exit(1);
  }
  return string[top--];
}

int main(void)
{
  int k; printf("Enter the number of character you want to enter: "); scanf("%d", &k);
  if (k>0 && k<=MAX)
  {
    char str[k];
    printf("Enter the string: ");
    unsigned int i;
    for (i=0; i<=k; i++)
    {
      char temp; scanf("%c", &temp);
      str[i] = temp;
      push(str[i]);
    }
    for (i=0; i<k; i++)
    {
      str[i] = pop();
    }
    for (i=0; i<k; i++)
    {
      printf("%c", str[i]);
    }
    printf("\n");
  }
}