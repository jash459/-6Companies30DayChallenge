// Link : https://leetcode.com/problems/trim-a-binary-search-tree/description/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return nullptr;
        if(low > root->val ) {
            return trimBST(root->right, low, high);
        } else if (high < root->val) {
            return trimBST(root->left, low, high);
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};