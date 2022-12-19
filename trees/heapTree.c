// https://www.sanfoundry.com/c-program-heap-sort-algorithm/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* new_node(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
        return new_node(data);
    if (data > root->data)
    {
        root->right = insert(root->right, data);
        return root;
    }
    else
    {
        root->left = insert(root->left, data);
        return root;
    }
}

void heapify(struct Node* root)
{
    struct Node* largest = root;
    if (root->left && root->left->data > largest->data)
        largest = root->left;
    if (root->right && root->right->data > largest->data)
        largest = root->right;
    if (largest != root)
    {
        int temp = root->data;
        root->data = largest->data;
        largest->data = temp;
        heapify(largest);
    }
}

void build_heap(struct Node* root)
{
    if (root->left)
        build_heap(root->left);
    if (root->right)
        build_heap(root->right);
    heapify(root);
}

void heap_sort(int arr[], int n)
{
    struct Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);
    build_heap(root);
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = root->data;
        root = delete(root, root->data);
        if (root)
          heapify(root);
    }
}

int main()
{
    // Test heap sort
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);  // Output: 1 3 4 5 10
    return 0;
}