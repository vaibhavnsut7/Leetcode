// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int f=-1;
//         int n=nums.size();
//         for (int i=n-2;i>=0;i--){
//             if (nums[i]<nums[i+1]){
//                 f=i;
//                 break;
//             }
//         }
//         if (f==-1){
//             reverse(nums.begin(),nums.end());
//             return;
//         }
//         int sec=-1;
//         for (int i=n-1;i>=0;i--){
//             if (nums[f]<nums[i]){
//                 sec=i;
//                 break;
//             }
//         }
//         swap(nums[f],nums[sec]);
//         reverse(nums.begin()+f+1,nums.end());
//     }    
    
//     int ConcatenateArr(vector<int> arr, int N)
// {
//     // Stores the resulting integer value
//     int ans = arr[0];
 
//     // Traverse the array arr[]
//     for (int i = 1; i < N; i++) {
 
//         // Stores the count of digits of
//         // arr[i]
//         int l = floor(log10(arr[i]) + 1); 
 
//         // Update ans
//         ans = ans * pow(10, l);
 
//         // Increment ans by arr[i]
//         ans += arr[i];
//     }
//     // Return the ans
//     return ans;
// }
//     int formnum(vector<int> arr){
//         int n=0;
//         int s=arr.size();
//         for (int i=s-1;i>=0;i--){
//             n+=arr[s-i]*pow(10,i);
//         }
//         return n;
//     }
//     int nextGreaterElement(int n) {
//         vector<int> v;
//         int x=n;
//         while(n!=0){
//             v.push_back(n%10);
//             n=n/10;
//         }
//         reverse(v.begin(),v.end());
//         nextPermutation(v);
//         int ans=ConcatenateArr(v,v.size());
//         // int ans=formnum(v);
//         if (ans>x)
//             return ans;
//         return -1;
        
//     }
// };
class Solution{
    public:
    int nextGreaterElement(int n) {
    auto digits = to_string(n);
    next_permutation(begin(digits), end(digits));
    auto res = stoll(digits);
    return (res > INT_MAX || res <= n) ? -1 : res;
}
};
    