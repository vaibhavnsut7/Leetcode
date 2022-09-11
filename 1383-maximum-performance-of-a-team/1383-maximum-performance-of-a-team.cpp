class Solution {
public:
    

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineers;

for (int i = 0; i < n; i++)
{
    engineers.push_back({efficiency[i], speed[i]});
}
// sort by efficiency and then by speed, descending
sort(engineers.rbegin(), engineers.rend());

// takung min heap, so used greater<int>
priority_queue<int, vector<int>, greater<int>> pq;
long long int sum = 0, ans = 0;

// itereate through efficiency
for (int i = 0; i < n; i++)
{
    sum += engineers[i].second;
    pq.push(engineers[i].second);

    if (pq.size() > k)
    {
        sum -= pq.top();
        pq.pop();
    }

    ans = max(ans, sum * engineers[i].first);
}
    
    
// why use % 1000000007? because in ques, it's written, *Since the answer can be a huge number, return it modulo 109 + 7.*
return ans % 1000000007;
    }
        
        
//         vector<pair<int,int>> eng;
//         for (int i=0;i<n;i++){
//             eng.push_back({efficiency[i],speed[i]});
//         }
//         sort(eng.rbegin(), eng.rend());

//         long long sum=0;
//         long long ans=0;
//         priority_queue<int,vector<int>,greater<int> >pq;
//         for (int i=0;i<n;i++){
//             sum+=eng[i].second;
//             pq.push(eng[i].second);
//             if (pq.size()>k){
//               sum-=pq.top();
//               pq.pop();
//             ans = max(ans, sum * eng[i].first);           
//            }
//         }
//         return ans%100000007;
//     }
    
    
};