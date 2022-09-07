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
    void bt2str(TreeNode* root,string &s){
        if (root==NULL){
            return ; 
        }
        s+=to_string(root->val);
        
        if (root->left!=NULL){
            s+='(';
            bt2str(root->left,s);
            s+=')';
        }
        if (root->right!=NULL){
            if (root->left==NULL)
               s+="()"; 
            s+='(';
            bt2str(root->right,s);
            s+=')';
        }
    }
    string tree2str(TreeNode* root) {
        string s="";
        bt2str(root,s);
        return s;
    }
};