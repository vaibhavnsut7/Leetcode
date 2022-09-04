class Solution {
public:
    struct mycomp{
        bool operator()(pair<string,int> p1, pair<string,int> p2){
            if (p1.second==p2.second)
                return p1.first>p2.first;
            return p1.second<p2.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for (string s:words){
            m[s]++;
        }
        
        priority_queue<pair<string,int>,vector<pair<string,int>>,mycomp> pq(m.begin(),m.end());
        vector<string> ans;
        for (int i=0;i<k;i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};