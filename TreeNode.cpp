#include "TreeNode.h"
#include <iostream>

TreeNode* createNode(int data){
	std::cout<<"Treenode create\n";
	return new TreeNode(data);

}
int height(TreeNode* node){
	if(node == nullptr){
		return 0;
	} 
	return node->height;
}
void inOrderTraversal(TreeNode* root){
	if(root!=nullptr){
		inOrderTraversal(root->left);
		std::cout<<root->data<<" ";
		inOrderTraversal(root->right);
	}
}
TreeNode* insertBST(TreeNode* root,int data){
	if(root == nullptr){//insert new node
		return createNode(data);
	}
	if(data<root->data){//recursively walk down left path
		root->left= insertBST(root->left,data);
		std::cout<<"call: insert(leftpointer, data)\n";
	}else if(data>root->data){//recursively walk down right path
		root->right=insertBST(root->right,data);
		std::cout<<"call: insert(rightpointer, data)\n";		
	}else{
		return root;//enure no double data
	}
	return root;
}
int countNodes(TreeNode* root){
	if(root==nullptr){
		return 0;	
	}
	return 1+countNodes(root->left)+countNodes(root->right);
}

