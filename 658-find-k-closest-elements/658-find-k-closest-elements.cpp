class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        int n=arr.size();
        for (int i=0;i<k;i++){
            pq.push({abs(arr[i]-x),i});
        }
        for (int i=k;i<n;i++){
            if (abs(arr[i]-x)<pq.top().first){
                pq.pop();
                pq.push({abs(arr[i]-x),i});
            }
        }
        vector<int> ans;
        while (!pq.empty()){
            ans.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};