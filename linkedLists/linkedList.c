#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node;

node *createlist()
{
  node *tp, *head;
  int k, n; printf("Enter the number of nodes to create: "); scanf("%d", &n);
  for (k=0; k<n; k++)
  {
      if (k==0)
      {
          head = (node *)malloc(sizeof(node));
          tp = head;
      }
      else
      {
          tp->next = (node *)malloc(sizeof(node));
          tp = tp->next;
      }
      printf("Enter data of node (%d): ", k+1); scanf("%d", &tp->data);
  }
  tp->next = NULL;
  return head;
}

void display(node *head)
{
  node *tp=head;
  while(tp!=NULL)
  {
      printf("\n%d", tp->data);
      tp = tp->next;
  }
}

void insert(node **head)
{
  node *tp = *head, *new, *tq;
  int k; printf("\nEnter the key value: "); scanf("%d", &k);
  new = (node *)malloc(sizeof(node));
  printf("Enter the data of new node: "); scanf("%d", &new->data);
  if (tp->data==k)
  {
      new->next = *head;
      *head = new;
  }
  else
  {
      while(tp->next!=NULL && tp->data!=k)
      {
          tq = tp;
          tp = tp->next;
      }
      if (tp==NULL)
      {
          tp->next = new;
          new->next = NULL;
      }
      else
      {
          tq->next = new;
          new->next = tp;
      }
  }
}

void delete(node **head)
{
  node *tp=*head, *tq;
  int k; printf("\nEnter the node value to delete: "); scanf("%d", &k);
  if (tp->data==k)
  {
      tq = tp;
      *head = tp->next;
      free(tq);
  }
  else
  {
      while(tp->next!=NULL && tp->data!=k)
      {
          tq = tp;
          tp = tp->next;
      }
      if (tp->data==k)
      {
          tq->next = tp->next;
          free(tp);
      }
      else
      {
          printf("No such node present");
      }
  }
}

int main()
{
  node *head = createlist();
  display(head);
  insert(&head);
  display(head);
  delete(&head);
  display(head);
}
