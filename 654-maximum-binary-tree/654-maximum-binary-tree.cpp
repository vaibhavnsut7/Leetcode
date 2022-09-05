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
    TreeNode* cons(vector<int> &nums,int s,int e){
        if (s>e)
            return NULL;
        int maxnum=INT_MIN;
        int index=-1;
        for (int i=s;i<=e;i++){
            if (nums[i]>maxnum){
                maxnum=nums[i];
                index=i;
            }
        }
    
        TreeNode *curr=new TreeNode(maxnum);
        curr->left=cons(nums,s,index-1);
        curr->right=cons(nums,index+1,e);
        return curr;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return cons(nums,0,nums.size()-1);
        // return curr;
    }
};