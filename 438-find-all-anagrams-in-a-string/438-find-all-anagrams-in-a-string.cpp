class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[256]={0};
        for (char ch:s){
            count[ch]++;
        }
        for (char ch:t){
            count[ch]--;
        }
        for (int i=0;i<256;i++){
            if (count[i]!=0)
                return false;
        }
        return true;
    }
    bool areSame(int cp[],int cs[]){
        for (int i=0;i<256;i++){
            if (cp[i]!=cs[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=s.length();
        int m=p.length();
        if (n<m)
            return ans;
        int cs[256]={0};
        int cp[256]={0};
        for (int i=0;i<m;i++){
            cp[p[i]]++;
            cs[s[i]]++;
        }
        if (areSame(cs,cp)){
                ans.push_back(0);
        }
        for (int i=m;i<n;i++){
            cs[s[i-m]]--;
            cs[s[i]]++;
            if (areSame(cs,cp)){
                ans.push_back(i-m+1);
            }

        }
        

        return ans;
    }
};
