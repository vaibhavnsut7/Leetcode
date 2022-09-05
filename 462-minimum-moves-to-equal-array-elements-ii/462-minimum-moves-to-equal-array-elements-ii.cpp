class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int s=0;
        int e=n-1;
        int moves=0;
        while (s<=e){
            moves+=nums[e]-nums[s];
            s++;
            e--;
        }
        return moves;
//         int n=nums.size();
//         int moves=0;
//         int median;
//         sort(nums.begin(),nums.end());
//         if (n%2!=0)
//             median=nums[n/2];
//         else
//             median=(nums[n/2]+nums[n/2-1])/2;
        
//         for (int num:nums){
//             moves+=abs(num-median);
//         }
//         return moves;
        
    }
};