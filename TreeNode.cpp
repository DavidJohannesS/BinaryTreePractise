#include "TreeNode.h"
#include <iostream>

TreeNode *createNode(int data)
{
    // std::cout<<"Treenode create\n";
    return new TreeNode(data);
}
int height(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}
void inOrderTraversal(TreeNode *root)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}
TreeNode *insertBST(TreeNode *node, int data)
{
    // 1. Perform the normal BST rotation
    if (node == nullptr)
        return (createNode(data));

    if (data < node->data)
        node->left = insertBST(node->left, data);
    else if (data > node->data)
        node->right = insertBST(node->right, data);
    else // Equal data are not allowed in BST
        return node;

    // 2. Update the height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data < node->left->data)
    {
        std::cout << "bal(" << node->data << ") = " << balance << " (AVL violation!)" << std::endl;
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && data > node->right->data)
    {
        std::cout << "bal(" << node->data << ") = " << balance << " (AVL violation!)" << std::endl;
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        std::cout << "bal(" << node->data << ") = " << balance << " (AVL violation!)" << std::endl;
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        std::cout << "bal(" << node->data << ") = " << balance << " (AVL violation!)" << std::endl;
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
}

TreeNode *findMin(TreeNode *node)
{
    TreeNode *current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

// Function to find the maximum value in the BST
TreeNode *findMax(TreeNode *node)
{
    TreeNode *current = node;
    while (current && current->right != nullptr)
    {
        current = current->right;
    }
    return current;
}
int sumKeys(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->data + sumKeys(root->left) + sumKeys(root->right);
}

double calculateAverage(TreeNode *root)
{
    int sum = sumKeys(root);
    int count = countNodes(root);
    if (count == 0)
    {
        return 0; // To avoid division by zero
    }
    return static_cast<double>(sum) / count;
}
int countNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
void updateHeight(TreeNode *node)
{
    if (node != nullptr)
    {
        node->height = max(height(node->left), height(node->right)) + 1;
    }
}
TreeNode *rightRotate(TreeNode *y)
{
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    // Return new root
    return x;
}

TreeNode *leftRotate(TreeNode *x)
{
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    // Return new root
    return y;
}
TreeNode *leftRightRotate(TreeNode *z)
{
    z->left = leftRotate(z->left);
    return rightRotate(z);
}
TreeNode *rightLeftRotate(TreeNode *z)
{
    z->right = rightRotate(z->right);
    return leftRotate(z);
}
int getBalance(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

bool isAVL(TreeNode *node)
{
    if (node == nullptr)
    {
        // An empty tree is AVL
        return true;
    }

    // Get the balance factor
    int balance = getBalance(node);

    // Check if the current node is balanced and recursively check the subtrees
    return abs(balance) <= 1 && isAVL(node->left) && isAVL(node->right);
}
void printBalanceFactors(TreeNode *node)
{
    if (node != nullptr)
    {
        printBalanceFactors(node->left);
        int balance = getBalance(node);
        std::cout << "bal(" << node->data << ") = " << balance;
        if (abs(balance) > 1)
        {
            std::cout << " (AVL violation!)";
        }
        std::cout << std::endl;
        printBalanceFactors(node->right);
    }
}
TreeNode *search(TreeNode *root, int data)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == data)
        return root;

    // Key is greater than root's key
    if (root->data < data)
        return search(root->right, data);

    // Key is smaller than root's key
    return search(root->left, data);
}
