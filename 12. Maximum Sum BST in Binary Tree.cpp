// Link : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

class Solution {
public:
    struct TreeDetails {
        bool isBST;
        int minm;
        int maxm;
        int sum;
        TreeDetails (bool a, int b, int c, int d) {
            isBST = a;
            minm = b;
            maxm = c;
            sum = d;
        }
    };

// core function
    TreeDetails* solve (TreeNode* root, int &temp) {
        if (!root) return new TreeDetails (true, INT_MAX, INT_MIN, 0);

        // traverse in postorder
        TreeDetails *left = solve(root->left, temp);
        TreeDetails *right = solve(root->right, temp);

        // CORE UPDATE logic for the 4 variables
        bool isBST = left->isBST && right->isBST && root->val > left->maxm && root->val < right->minm ;

        int sum = left->sum + right->sum + root->val;
        if (isBST) temp = max(sum, temp);

        int minm = min(root->val, min(left->minm, right->minm));
        int maxm = max(root->val, max(left->maxm, right->maxm));

        //return
        return new TreeDetails (isBST, minm, maxm, sum);
    }


// driver function
    int maxSumBST(TreeNode* root) {
        int temp = 0;
        solve(root, temp);
        return temp;
    }
};