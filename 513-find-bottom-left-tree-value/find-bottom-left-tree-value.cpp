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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* current;
        queue<TreeNode*> q;
        q.push(root);
        int val;

        while(!q.empty()){
            int level = q.size();
            vector<int> v;
            for(int i = 0; i<level; i++){
                current = q.front();
                v.push_back(current->val);
                q.pop();
                
                if(current->left != nullptr) q.push(current->left);
                if(current->right != nullptr) q.push(current->right);
            }
            if(q.empty()) val = v[0];
        }
        return val;
    }
};