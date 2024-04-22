#include <iostream>
#include <iomanip> // For std::setprecision
#include "TreeNode.h"
#include <fstream>
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
        return 1;
    }
    std::ifstream inputFile(argv[1]);
    int key;
    TreeNode* root = nullptr;

    if (inputFile.is_open()) {
        while (inputFile >> key) {
            // Insert key into the tree and balance it
            root = insertBST(root, key);
        }
        inputFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
        return 1; // Exit with an error code
    }

    // Print the balance factors and check for AVL violations
    //printBalanceFactors(root);

    // Check if the tree is an AVL tree
    std::cout << "AVL: " << (isAVL(root) ? "yes" : "no") << std::endl;

    // Print the statistical data
    std::cout << "min: " << findMin(root)->data << ", ";
    std::cout << "max: " << findMax(root)->data << ", ";
    std::cout << "avg: " << std::fixed << std::setprecision(1) << calculateAverage(root) << std::endl;

    // User interaction loop
    while (true) {
        std::cout << "Enter a key to search for (or -1 to exit): ";
        std::cin >> key;

        // Exit condition
        if (key == -1) {
            break;
        }

        // Search for the key
        TreeNode* result = search(root, key);
        if (result != nullptr) {
            std::cout << "Key " << key << " found in the tree." << std::endl;
        } else {
            std::cout << "Key " << key << " not found in the tree." << std::endl;
        }
    }

    return 0;
}
