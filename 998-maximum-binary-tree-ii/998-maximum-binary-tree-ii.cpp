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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root==NULL){
            return new TreeNode (val);
        }
        if (val>root->val){
            TreeNode *n=new TreeNode(val);
            n->left=root;
            return n;
        }
        root->right=insertIntoMaxTree(root->right,val);
        return root;

    }
};