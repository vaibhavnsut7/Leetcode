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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int level=0;
        bool reverse=false;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode *> level;
            for (int i=0;i<n;i++){
                TreeNode *curr=q.front();
                q.pop();
                if (curr->left!=NULL)
                    q.push(curr->left);
                if (curr->right!=NULL)
                    q.push(curr->right);
                level.push_back(curr);
            }
            if (reverse){
                int s=0;
                int e=level.size()-1;
                while(s<=e){
                    int x=level[s]->val;
                    int y=level[e]->val;
                    level[s]->val=y;
                    level[e]->val=x;
                    s++;
                    e--;
                }
                reverse=false;
            }
            else{
                reverse=true;
            }
        }
        return root;
    }
};