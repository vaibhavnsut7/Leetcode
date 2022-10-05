class Solution {
public:
    int rolls(int n,int k,int target,vector<vector<int>> &dp){
        if (target<0)
            return 0;
        if (n==0 && target==0)
            return 1;
        if (n==0 && target!=0)
            return 0;
        if (target==0 && n!=0)
            return 0;
        if (dp[n][target]!=-1){
            return dp[n][target];
        }
        int ans=0;
        for (int i=1;i<=k;i++){
            ans=(ans+rolls(n-1,k,target-i,dp))% 1000000007;
        }
         dp[n][target]=ans;
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return rolls(n,k,target,dp);
    }
};