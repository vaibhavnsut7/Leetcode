class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int s = i + 1;
            int l = nums.size()-1;
            while(s < l){
                int sum = nums[i] + nums[s] + nums[l];
                if(sum == 0){
                    ans.insert({nums[i],nums[s],nums[l]});
                    s++;
                    l--;
                }
                else if(sum > 0){
                    l--;
                }
                else if(sum < 0){
                    s++;   
                }
            }
            while(i < nums.size()-1 && nums[i] == nums[i+1])i++;
        }
        vector<vector<int>> numds;
        for(auto i : ans)numds.push_back(i);
        return numds;
    }
};