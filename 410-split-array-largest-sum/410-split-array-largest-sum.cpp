class Solution {
public:

    //Allocate Minimum Pages (Binary Search)
    bool isfeasible(vector<int> &nums,int n,int ans,int m){
        int req=1;
        int sum=0;
        for (int i=0;i<n;i++){
            if (sum+nums[i]>ans){
                req++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return req<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int maxsum=INT_MIN;
        int sum=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            sum+=nums[i];
            maxsum=max(maxsum,nums[i]);
        }
        int res=0;
        int low=maxsum;
        int high=sum;
        while (low<=high){
            int mid=(low+high)/2;
            if (isfeasible(nums,n,mid,m)){
                res=mid;
                high=mid-1;
            }
            else{
                low=low=mid+1;
            }
        }
        return res;
    }
};