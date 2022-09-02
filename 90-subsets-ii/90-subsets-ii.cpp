class Solution {
public:
    void subset(vector<int>& nums,vector<int> curr,vector<vector<int>> &ans,int index){
        ans.push_back(curr);
        for (int i=index;i<nums.size();i++){
            if (i!=index && nums[i]==nums[i-1])
                continue;
            curr.push_back(nums[i]);
            subset(nums,curr,ans,i+1);
            curr.pop_back();
            // subset(nums,curr,ans,i+1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0;
        vector<int> curr;
        subset(nums,curr,ans,i);
        return ans;
    }
};