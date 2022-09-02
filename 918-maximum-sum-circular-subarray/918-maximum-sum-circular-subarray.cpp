class Solution {
public:
    int kadane(vector<int>& nums){
        int maxend=nums[0];
        int n=nums.size();
        int ans=maxend;
        for (int i=1;i<n;i++){
            maxend=max(maxend+nums[i],nums[i]);
            ans=max(ans,maxend);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int normal=kadane(nums);
        int n=nums.size();
        if (normal<0)
            return normal;
        int arrsum=0;
        for (int i=0;i<n;i++){
            arrsum+=nums[i];
            nums[i]=-nums[i];
        }
        int maxcircular=arrsum-(-kadane(nums));
        return max(normal,maxcircular);
    }
};