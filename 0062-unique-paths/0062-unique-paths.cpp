class Solution {
public:
    int path(vector<vector<int>> &dp,int i,int j,int &m,int &n){
        if (i==m-1 || j==n-1)
            return 1;
        if (dp[i][j]!=0)
            return dp[i][j];
        
        dp[i][j]=path(dp,i+1,j,m,n)+path(dp,i,j+1,m,n);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m , vector<int>(n , 0));
        return path(dp,0,0,m,n);
    }
};