#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;  // If root is null or p or q, return root.
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);   // Search in left subtree.
    TreeNode* right = lowestCommonAncestor(root->right, p, q); // Search in right subtree.

    if (left != NULL && right != NULL) {
        return root;  // If both left and right are non-NULL, root is the LCA.
    }

    return left != NULL ? left : right;  // If either left or right is non-NULL, return the non-NULL one.
}

int main() {
    // Create an example binary tree
    //           3
    //         /   \
    //        5     1
    //       / \   / \
    //      6   2 0   8
    //         / \
    //        7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;   // Node 5
    TreeNode* q = root->right;  // Node 1

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "LCA of " << p->val << " and " << q->val << " is " << lca->val << endl;
    } else {
        cout << "No LCA found." << endl;
    }

    return 0;
}
