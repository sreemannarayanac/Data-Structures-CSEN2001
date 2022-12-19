# Trees
## What is a tree?
A tree is a type of data structure that consists of nodes organized in a hierarchy. Each node in a tree has a value, and it may have one or more child nodes. The node at the top of the hierarchy is called the root node, and the nodes that do not have any child nodes are called leaf nodes.  
Structure of the node looks like  
```C
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
}
```
or in Python we have class structure as  
```Python
class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None
```
Here the ` struct Node ` have three elements ` data `, ` left ` and ` 
right `. The ` left ` and ` right ` represents the left and right subtree of the parent node.

## Binary Tree
A binary tree is a type of tree data structure in which each node has at most two children. The children of a node are referred to as the left child and the right child.

Here is an example of a binary tree:  
```    
    10  
   /  \  
  5    15  
 / \   / \  
2   7 12  20
```
### Types of Binary Tree
#### 1. Full Binary Tree
A full binary tree (also known as a proper binary tree) is a binary tree in which every node has either 0 or 2 children. In other words, all leaf nodes in a full binary tree are at the same level and there are no nodes with only one child.

Here is an example of a full binary tree:
``` 
    10
   /  \
  5    15
 / \   
2   7

```
#### 2. Perfect Binary Tree
A perfect binary tree is a type of binary tree in which all the leaf nodes are at the same level and all the internal nodes have two children.

Here is an example of a perfect binary tree:
```
    10
   /  \
  5    15
 / \   / \
2   7 12  20
```
#### 3. Complete Binary Tree
A complete binary tree is a special type of binary tree in which every level of the tree is completely filled, except possibly the last level, and all nodes are as far left as possible.

Here is an example of a complete binary tree:
```
    10
   /  \
  5    15
 /
2 
```
## Tree Traversals
### 1. In-order
```

```
### 2. Pre-order
```

```
### 3. Post-order
```

```
***
# Binary Search Tree
## What is a Binary Search Tree(BST)
It is a binary tree which follows folowing conditions:
1. Duplicate elements should not be inserted in a BST.
2. The left child of a node contains a value less than its parent node's value.
3. The right child of a node contains a value greater than its parent node's value.
4. The left and right subtrees of a node are also binary search trees.
Here is an example of a binary serch tree:
```
      5
     / \
    3   8
   / \   \
  2   4   9
```
## To delete a node from BST  
1. If node to be deleted is a leaf node ` simply delete the node as shown below `
```
      5
     / \
    3   8
   / \   \
  2   4   9
  
Tree after deleting node 9 from the above tree:

      5
     / \
    3   8
   / \   \
  2   4   9
```
2. If node have only one children ` point the pointer to child and delete the node as shown below `
```
      5
     / \
    3   8
   / \   \
  2   4   9

Tree after deleting node 8 from the above tree:

      5
     / \
    3   9
   / \
  2   4
```
3. If node have two children ` point the pointer to the smallest value of right subtree and delete the node as shown below `
```
      6
     / \
    5   8
   / \   \
  2   4   9
     /
    3

Tree after deleting node 5 from the above tree:

      6
     / \
    3   8
   / \   \
  2   4   9
```