#include <stdio.h>
#include <stdlib.h>

#define size 10

int queue[size];
int front = -1, rear = -1;

void enqueue()
{
  int newData;
  if (rear==size-1)
  {
    printf("\nQueue is full\n");
  }
  else
  {
    if (front==-1)
    {
      ++front;
    }
    printf("Enter data of new queue element: ");
    scanf("%d", &newData);
    queue[++rear] = newData;
  }
}

int dequeue()
{
  int firstEle;
  if (front==-1)
  {
    printf("\nQueue is empty\n");
  }
  else
  {
    firstEle = queue[front];
    front++;
    if (front > rear)
    {
      front = -1;
      rear = -1;
    }
  }
  return firstEle;
}

int peek()
{
  if (front==-1)
  {
    printf("Empty Queue");
    return -1;
  }
  else
  {
    return queue[front];
  }
}

void display()
{
  printf("\n____Queue____\n");
  for(int i=front; i<=rear; i++)
  {
    printf("%d ", queue[i]);
  }
  printf("\n\n");
}

int main(void)
{
  int ch;
  while (1)
  {
    printf("\n1.Enqueue Operation\n");
    printf("2.Dequeue Operation\n");
    printf("3.Display the first element\n");
    printf("4.Display the queue\n");
    printf("5.Exit\n");
    printf("Enter your choice of operations : ");
    scanf("%d", &ch);
    switch (ch)
    {
      case 1: enqueue(); break;
      case 2: printf("Deleted element of Queue = %d\n", dequeue()); break;
      case 3: printf("First element of Queue = %d\n", peek()); break;
      case 4: display(); break;
      case 5: exit(0);
      default: printf("Incorrect choice \n");
    } 
  } 
}