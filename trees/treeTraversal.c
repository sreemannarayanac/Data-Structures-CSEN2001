#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *leftChild;
  struct node *rightChild;
} node;

node *createNode(void)
{
  int data;
  printf("\nEnter data of new Node: "); scanf("%d", &data);
  node *new = (node *)malloc(sizeof(node));
  new->data = data;
  new->leftChild = NULL;
  new->rightChild = NULL;

  return new;
}

node* insertLeft(node *parent)
{
  parent->leftChild = createNode();
  return parent->leftChild;
}

node* insertRight(node *parent)
{
  parent->rightChild = createNode();
  return parent->rightChild;
}

void inorderTraversal(struct node* parent) {
  if (parent == NULL) 
    return;
  else
  {
    inorderTraversal(parent->leftChild);
    printf("%d ->", parent->data);
    inorderTraversal(parent->rightChild);
  }
}

void preorderTraversal(struct node* parent) {
  if (parent == NULL) 
    return;
  else
  {
    printf("%d ->", parent->data);
    preorderTraversal(parent->leftChild);
    preorderTraversal(parent->rightChild);
  }
}

void postorderTraversal(struct node* parent) {
  if (parent == NULL) 
    return;
  else
  {
    postorderTraversal(parent->leftChild);
    postorderTraversal(parent->rightChild);
    printf("%d ->", parent->data);
  }
}

int main(void)
{
  node *root = createNode();
  insertLeft(root);
  insertRight(root);

  insertLeft(root->leftChild);
  insertRight(root->leftChild);

  printf("\nInorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);

  printf("\n");
}