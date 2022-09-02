class Solution {
public:
    void subset(vector<int>& nums,vector<int> curr,vector<vector<int>> &ans,int i){
        if (i==nums.size()){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[i]);
        subset(nums,curr,ans,i+1);
        curr.pop_back();
        subset(nums,curr,ans,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int i=0;
        vector<int> curr;
        subset(nums,curr,ans,i);
        return ans;
    }
};