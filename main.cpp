#include <iostream>
#include <iomanip>
#include "TreeNode.h"
#include <fstream>

int main(){
	std::ifstream inputFile("keys.txt");
	int data;
	TreeNode* root=nullptr;

	if(inputFile.is_open()){
		while(inputFile>>data){
			root=insertBST(root, data);
			inOrderTraversal(root);
		}
		inputFile.close();

		}else{ 
			std::cout<<"Open File error\n";
			return 1;	
		}
//	printBalanceFactors(root);
//	std::cout << "AVL: " << (is
}
