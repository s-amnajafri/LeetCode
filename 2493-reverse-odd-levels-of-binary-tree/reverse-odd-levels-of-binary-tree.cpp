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
    void reverse(vector<TreeNode*> &arr){
        int j = arr.size()-1;
        int i = 0;
        while(i<j){
            swap(arr[i]->val, arr[j]->val);
            i++;
            j--;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* current;

        int level = 0;
        q.push(root);

        while(!q.empty()){
            vector<TreeNode*> v;
            int n = q.size();

            for(int i = 0; i < n; i++){
                current = q.front();
                v.push_back(current);
                q.pop();

                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }

            if(level % 2 != 0)
                reverse(v);
            level++;
        }
        return root;
    }
};