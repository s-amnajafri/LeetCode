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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr && q != nullptr)
            return false;
        if(p != nullptr && q == nullptr)
            return false;
        if(p->val != q->val) return false;

        bool left = isSameTree(p->left, q->left);
        if(!left) return false;
        bool right = isSameTree(p->right, q->right);
        if(!right) return false;

        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* current = nullptr;
        vector<TreeNode*> v;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            current = q.front();
            q.pop();
            if(current->val == subRoot->val){
                v.push_back(current);
                
            }
            if(current->left != nullptr) q.push(current->left);
            if(current->right != nullptr) q.push(current->right);
        }
        if(v.size() < 1) return false;

        else {
            bool res = false;
            for(int i = 0; i<v.size(); i++){
                res = isSameTree(v[i], subRoot);
                if(res == true)
                    break;
            }
            return res;
        }
    }
};