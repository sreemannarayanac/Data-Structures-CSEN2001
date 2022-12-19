#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} node;

node *root=NULL;

node *create(int data)
{
  node *Node = (node *)malloc(sizeof(node));
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;

  return Node;
}

node *insert(node *root, int data)
{
  if (root==NULL)
    return create(data);
  else
  {
    if (data > root->data)
      root->right = insert(root->right, data);
    else
      root->left = insert(root->left, data);
  }

  return root;
}

void inorder(node *root)
{
  if (root!=NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main(void)
{
  root = insert(root, 12);
  root = insert(root, 11);
  root = insert(root, 10);
  root = insert(root, 45);
  root = insert(root, 0);
  inorder(root);
}