class Solution {
public:
    int countPrimeSetBits(int &left, int &right) {
        vector<int> v = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0};
        int ans = 0,x,k;
        while(left <= right){
            x = 0;
            k = left;
            while(k){
                x += (k&1);
                k = k >> 1;
            }
            ans += v[x];
            left++;
        }
        return ans;
    }
};