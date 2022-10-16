class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int minval=matrix[0][0];
        int maxval=matrix[n-1][n-1];
        while (minval<maxval){
            int mid=minval+(maxval-minval)/2;
            int midpos=0;
            for (int i=0;i<n;i++){
                midpos+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if (midpos<k){
                minval=mid+1;
            }
            else{
                maxval=mid;
            }
        }
        return minval;
    }
};