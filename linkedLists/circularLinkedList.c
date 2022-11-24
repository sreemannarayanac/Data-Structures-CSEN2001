#include <stdio.h>
#include <stdlib.h>

// Program to create a circular linked list and do the following
// 1. Insert
// 2. Delete
// 3. Traverse

typedef struct item{
    int data;
    struct item *next;
} node;

void display(node *head){
    node *tp = head;
    int loopTerm = 1;
    while (loopTerm){
        if (tp->next == head){
            printf("%d", tp->data);
            loopTerm = 0;
        }
        else{
            printf("%d ->", tp->data);
            tp = tp->next;
        }
    }
}

void Cinsert(node **head){
    node *tp = *head, *tq, *new;
    int k; printf("\nEnter key value to insert a new node before it: "); scanf("%d", &k);
    new = (node *)malloc(sizeof(node));
    printf("Enter data of new node: "); scanf("%d", &new->data);
    if (tp->data == k){ // insert at beginning
        tq = tp;
        while (tq->next!=*head){
            tq = tq->next;
        }
        new->next = *head;
        tq->next = new;
        *head = new;
    }
    else{
        while((tp->next!=*head && tp->data!=k)){
            tq=tp;
            tp = tp->next;
        }
        if (tp->next==*head){//insert at end
            tp->next = new;
            new->next = *head;
        }
        else{//insert in middle
            tq->next = new;
            new->next = tp;
        }
    }
}

void Cdelete(node **head){
    node *tp=*head, *tq;
    int k; printf("\nEnter the key you want to delete: "); scanf("%d", &k);
    if (tp->data == k){
        tq = tp;
        // tp = tp->next;
        *head = tp->next;
        free(tq);
    }
    else{
        while((tp->next!=*head) && (tp->data!=k)){
            tq = tp;
            tp = tp->next;
        }
        if (tp->data==k){
            tq->next = tp->next;
            free(tp);
        }
        else{
            printf("\nNo node matches the key value.");
        }
    }
}

node* create_Clist(){
    node *tp, *head;
    int k, n;
    printf("Ënter the # of nodes: "); scanf("%d", &n);
    for (k=0; k<n; k++){
        if (k==0){
            head = (node *)malloc(sizeof(node));
            tp = head;
        }
        else {
            tp->next = (node *)malloc(sizeof(node));
            tp = tp->next;
        }
        printf("Enter data of node(%d): ", k+1); scanf("%d", &tp->data);
    }
    tp->next = head;
    return (head);
}

int main(void){
    node *head = create_Clist();
    display(head);
    Cinsert(&head);
    display(head);
    Cdelete(&head);
    display(head);
}