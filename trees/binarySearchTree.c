#include <stdio.h>
#include <stdlib.h>

// This is a simple program to create and perform different operations on a binary tree

// Structure of the tree element
typedef struct node
{
  int data;
  struct node* left;
  struct node* right;
} node;

node *root = NULL; // creating root node

void insertNode(int data)
{
  // creating a new node
  node *Node = (node *)malloc(sizeof(node)); 
  Node->data = data; // setting data of node to the input received as the function argument
  Node->left=NULL;
  Node->right=NULL;
  // checking if the binary search tree is empty
  if (root==NULL)
  {
    // binary tree is empty, now setting the new element as root
    root = Node;
  }
  else
  {
    node *current = root;
    // now compare the new data with the current node
    while (current!=NULL)
    {
      // left
      if (data < current->data)
      {
        if (current->left == NULL)
        {
          current->left = Node;
          break;
        }
        else
        {
          current = current->left;
        }
      }
      // right
      if (data > current->data)
      {
        if (current->right == NULL)
        {
          current->right = Node;
          break;
        }
        else
        {
          current = current->right;
        }
      }
    }
  } 
}

void inorderTraversal(struct node* Node) {
  if (Node == NULL) 
    return;
  else
  {
    inorderTraversal(Node->left);
    printf("%d ->", Node->data);
    inorderTraversal(Node->right);
  }
}

void postorderTraversal(struct node* Node) {
  if (Node == NULL) 
    return;
  else
  {
    postorderTraversal(Node->left);
    postorderTraversal(Node->right);
    printf("%d ->", Node->data);
  }
}

int main(void)
{
  insertNode(3);
  insertNode(12);
  insertNode(7);
  insertNode(11);
  inorderTraversal(root);
  printf("\n");
  insertNode(0);
  inorderTraversal(root);
  printf("\n");
  postorderTraversal(root);
}