class Solution {
public:
    bool mirror(TreeNode* left, TreeNode* right) {

        // Both are NULL
        if (left == NULL && right == NULL)
            return true;

        // One is NULL
        if (left == NULL || right == NULL)
            return false;

        // Values are different
        if (left->val != right->val)
            return false;

        // Check mirror children
        return mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == NULL)
            return true;

        return mirror(root->left, root->right);
    }
};