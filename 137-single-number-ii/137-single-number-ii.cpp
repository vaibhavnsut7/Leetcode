class Solution {
public:
    bool getbit(int n, int k)
    {
        return (n&(1<<k)) == (1<<k);
    }
    int setbit(int n,int pos){
        return (n | (1<<pos));
    }

    int singleNumber(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for (int i=0;i<32;i++){
            int sum=0;
            for (int j=0;j<n;j++){
                if (getbit(nums[j],i)==1){
                   sum+=1;
                }
            }
            if (sum%3!=0){
                res=setbit(res,i);
            }
        }
        return res;
        
    }
};