#ifndef TREENODE_H
#define TREENODE_H 
#include <cmath>

struct TreeNode{
	int data;
	TreeNode *left;
	TreeNode *right;
	int height;
	TreeNode(int x) : data(x), left(nullptr), right(nullptr), height(1){}
};

TreeNode* createNode(int data);
int height(TreeNode* node);
TreeNode* insertBST(TreeNode* root,int data);
void inOrderTraversal(TreeNode* root);
int countNodes(TreeNode* root);
#endif