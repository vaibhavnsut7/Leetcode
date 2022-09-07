class Solution {
public:
    int minlen(vector<int>& nums,int num,int fre){
        int n=nums.size();
        int f;
        int l;
        int count=0;
        for (int i=0;i<n;i++){
            if(nums[i]==num){
                f=i;
                break;
            }
        }
        for (int i=f+1;i<n;i++){
            if (nums[i]==num){
                l=i;
                count++;
            }
            if (count==fre)
                break;
        }
        return l-f+1;
        
    }
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=INT_MAX;
        vector<int> vec;
        int deg=-1;
        int num=-1;
        for (auto x:m){
            if (x.second>deg){
                deg=x.second;
            }
        }
        for (auto x:m){
            if (x.second==deg){
                vec.push_back(x.first);
            }
        }
        for (int i:vec){
            ans=min(ans,minlen(nums,i,deg));
        }
        if (deg==1){
            return 1;
        }
        return ans;
        
        
    }
};