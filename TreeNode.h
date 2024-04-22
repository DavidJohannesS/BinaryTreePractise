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
TreeNode* findMin(TreeNode* node);
TreeNode* findMax(TreeNode* node);
double calculateAverage(TreeNode* root);
void inOrderTraversal(TreeNode* root);
int countNodes(TreeNode* root);
int max(int a, int b);
void updateHeight(TreeNode* node);
TreeNode* rightRotate(TreeNode* y);
TreeNode* leftRotate(TreeNode* x);
TreeNode* leftRightRotate(TreeNode* z);
TreeNode* rightLeftRotate(TreeNode* z);
int getBalance(TreeNode* node);
bool isAVL(TreeNode* node);
void printBalanceFactors(TreeNode* node);
int sumKeys(TreeNode* root);
TreeNode* search(TreeNode* root, int data);
#endif