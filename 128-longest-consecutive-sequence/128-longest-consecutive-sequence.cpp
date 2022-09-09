class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int res=0;
        for (int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for (int i=0;i<nums.size();i++){
            if (s.find(nums[i]-1)==s.end()){
                int count =1;
                while (s.find(nums[i]+count)!=s.end()){
                    count++;
                }
                res=max(res,count);
            }
            
        }
        return res;
    }
};