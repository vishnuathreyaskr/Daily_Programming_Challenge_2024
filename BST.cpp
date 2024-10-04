#include <iostream>
#include <limits.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to validate the BST
bool isValidBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
    // Base case: if the node is null, it's a valid BST
    if (!node) return true;
    
    // Check the current node's value against the allowed min and max values
    if (node->val <= minVal || node->val >= maxVal) return false;
    
    // Recursively check the left and right subtrees
    return isValidBSTHelper(node->left, minVal, node->val) && 
           isValidBSTHelper(node->right, node->val, maxVal);
}

// Main function to check if a binary tree is a valid BST
bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    // Example 1: root = [2, 1, 3]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << (isValidBST(root1) ? "true" : "false") << endl;  // Output: true

    // Example 2: root = [5, 1, 4, null, null, 3, 6]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << (isValidBST(root2) ? "true" : "false") << endl;  // Output: false

    // Example 3: root = [10, 5, 15, null, null, 6, 20]
    TreeNode* root3 = new TreeNode(10);
    root3->left = new TreeNode(5);
    root3->right = new TreeNode(15);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(20);
    cout << (isValidBST(root3) ? "true" : "false") << endl;  // Output: false

    return 0;
}
