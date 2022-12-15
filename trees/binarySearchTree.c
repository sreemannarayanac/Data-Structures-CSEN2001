#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool search(int data)
{
  node *temp = root;
  while (temp!=NULL)
  {
    if (temp->data == data)
      return true;
    else
    {
      if (data > temp->data)
        temp = temp->right;
      else
        temp = temp->left;
    }
  }
  return false;
}

node* minValueNode(struct node* node)
{
  struct node* current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

node* deleteNode(node *root, int data)
{
  if (root == NULL) return root;
  if (data < root->data)
   root->left = deleteNode(root->left, data);
  else if (data > root->data)
   root->right = deleteNode(root->right, data);
  else
  {
    if (root->left == NULL)
    {
     node *temp = root->right;
     free(root);
     return temp;
    }
    else if (root->right == NULL)
    {
     node *temp = root->left;
     free(root);
     return temp;
    }
    struct node* temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
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
  if (search(8))
    printf("\nElement is present in the tree\n");
  else
    printf("\nElement is not present in the tree\n");
  deleteNode(root, 11);
  printf("Tree after deleting node with data = 11\n");
  inorderTraversal(root);
  printf("\n");
}