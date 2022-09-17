class Solution {
public:
    int bsf(vector<int> &nums,int x){
        int low=0;
        int high=nums.size()-1;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (x>nums[mid]){
                low=mid+1;
            }
            else if (x<nums[mid]){
                high=mid-1;
            }
            else if (mid==0 || nums[mid-1]!=nums[mid]){
                return mid;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
    int bsl(vector<int> &nums,int x){
        int low=0;
        int high=nums.size()-1;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (x>nums[mid]){
                low=mid+1;
            }
            else if (x<nums[mid]){
                high=mid-1;
            }
            else if (mid==nums.size()-1 || nums[mid+1]!=nums[mid]){
                return mid;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(bsf(nums,target));
        ans.push_back(bsl(nums,target));
        return ans;
    }
};