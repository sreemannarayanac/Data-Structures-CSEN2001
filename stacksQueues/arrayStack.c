#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], top = -1; // Creating an stack of array type

void push(int starr[], int new)
{
  if (top==MAX-1)
  {
    printf("\nStack Overflow!!!\n");
  }
  else
  {
    starr[++top] = new;
  }
}

int pop(int starr[])
{
  if (top == -1)
  {
    printf("\nStack Underflow!!!");
    return -1;
  }
  else
  {
    int val = starr[top--];
    return val;
  }
}

int peek(int starr[])
{
  if (top == -1)
  {
    printf("\nEmpty Stack!!!");
    return -1;
  }
  else
  {
    return starr[top];
  }
}

void display(int starr[])
{
  if (top == -1)
  {
    printf("\nEmpty Stack");
  }
  else
  {
    for(int i=top; i>=0; i--)
    {
      printf("\n%d", starr[i]);
    }
  }
  printf("\n");
}

int main(void)
{
  int opt, val;
  do
  {
    printf("\nSelect the operation you want to perform: ");
    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Peek");
    printf("\n4. Display");
    printf("\n5. Stop");
    printf("\nEnter number here: "); scanf("%d", &opt);
    switch (opt)
    {
    case 1:
      printf("\nEnter the value you want to push: "); scanf("%d", &val);
      push(stack, val);
      break;
    case 2:
      val = pop(stack);
      if (val!=-1)
      {
          printf("\nPopped element: %d\n", val);
      }
      break;
    case 3:
      val = peek(stack);
      if (val!=-1)
      {
          printf("\nTop element -> %d\n", val);
      }
      break;
    case 4:
      display(stack);
      break;
    case 5:
      exit(0);
    default:
      printf("\nEnter valid operation number\n");
    }
  } 
  while (opt!=5);
}