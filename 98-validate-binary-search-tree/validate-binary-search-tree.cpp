/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool recValidBST(TreeNode* root, long min, long max) {
        if (root == nullptr)
            return true;
        if (root->val <= min || root->val >= max)
            return false;

        bool validL = recValidBST(root->left, min, root->val);
        if (!validL) return false;

        bool validR = recValidBST(root->right, root->val, max);
        if (!validR) return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return recValidBST(root, LONG_MIN, LONG_MAX);
    }
};