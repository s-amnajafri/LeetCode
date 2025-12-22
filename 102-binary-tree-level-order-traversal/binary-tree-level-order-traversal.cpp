/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;

        queue<TreeNode*> q;
        TreeNode* current;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            for(int i = 0; i<n; i++){
                current = q.front();
                q.pop();
                v.push_back(current->val);
                if(current->left != nullptr)
                    q.push(current->left);
                if(current->right != nullptr)
                    q.push(current->right);
            }
            res.push_back(v);
        }
        return res;
    }
};