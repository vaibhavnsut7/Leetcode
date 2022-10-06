class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int n1=0,n2=0;
        long long XOR=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            XOR=XOR^nums[i];
        }
        
        long long ns=XOR&~(XOR-1);
        for (int i=0;i<n;i++){
            if ((nums[i]&ns)!=0){
                n1=n1^nums[i];
            }
            else{
                n2=n2^nums[i];
            }
        }
        ans.push_back(n1);
        ans.push_back(n2);
        return ans; 
    }
};