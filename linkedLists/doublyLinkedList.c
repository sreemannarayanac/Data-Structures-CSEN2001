#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
    int data;
    struct node *prev;
    struct node *next;
} node;

void display(node *head)
{
    node *tp = head;
    while (tp!=NULL)
    {
        if (tp->next==NULL)
        {
            printf("%d", tp->data);
            tp = tp -> next;
        }
        else
        {
            printf("%d -> ", tp->data);
            tp = tp->next;
        }
    }
}

node *create(int n)
{
    node *tp, *tq, *head;
    for (int k=0; k<n; k++)
    {
        if (k==0)
        {
            head = (node *)malloc(sizeof(node));
            tp = head;
            tq = NULL;
        }
        else
        {
            tp->next = (node *)malloc(sizeof(node));
            tp->prev = tq;
            tq = tp;
            tp = tp->next;
        }
        printf("Enter data of node(%d): ", k+1); scanf("%d", &tp->data);
    }
    tp->next = NULL;
    return (head);
}

bool search(node *head, int target)
{
    node *tp = head;
    while(tp!=NULL)
    {
        if (tp->data == target)
        {
            return true;
        }
        tp = tp->next;
    }
    return false;
}

void insert(node *head)
{
  node *tp = *head, *new = (node *)malloc(sizeof(node));
  int k; printf("Enter the key value, to enter new node before it: "); scanf("%d", &k);
  printf("Enter the data new node data: "); scanf("%d", &new->data);
  if (tp->data==k)  // insertion at beginning
  {
    new->next = *head;
    new->prev = NULL;
    *head = new;
  }
  else
  {
    while (tp->next!=NULL && tp->data!=k)
      {
        tq = tp;
        tp = tp->next;
      }
    if (tp->data==k) // insertion at end
    {
      new->next=tp;
      new->prev=tq;
      tq->next=new;
      tp->prev=new;
    }
  }
}

int main(){
    node *head = create(5);
    display(head);
    int n; printf("\nEnter the elemet to find: "); scanf("%d", &n);
    if(search(head, n))
    {
        printf("target found");
    }
    else
    {
        printf("target not found");
    }
}

