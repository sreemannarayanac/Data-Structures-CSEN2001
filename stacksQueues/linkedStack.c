#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *top = NULL;

struct stack *push(struct stack *top, int n)
{
    struct stack *new = (struct stack*)malloc(sizeof(struct stack));
    new -> data = n;
    if (top==NULL)
    {
        new -> next = NULL;
        top = new;
    }
    else
    {
        new->next = top;
        top = new;
    }
    return top;
}

struct stack *pop(struct stack *top)
{
    struct stack *ele;
    ele = top;
    if (top==NULL)
    {
        printf("\nEmpty Stack!!!");
    }
    else
    {
        top = top->next;  // makes top = NULL
        printf("\nElement popped = %d\n", ele->data);
        free(ele);
    }
    return top;
}

int peek(struct stack *top)
{
    if (top==NULL)
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}

void display(struct stack *top)
{
    struct stack *temp = top;
    if (top==NULL)
    {
        printf("\nEmpty Stack!!!");
    }
    else
    {
        while (temp!=NULL)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
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
                printf("\nEnter a value to push: "); scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                val = peek(top);
                if (val!=-1)
                {
                    printf("\nTop element -> %d\n", val);
                }
                else
                {
                    printf("Empty Stack!!!");
                }
                break;
            case 4:
                display(top);
                break;
        }
    }
    while (opt!=5 && opt>0 && opt<6);
}