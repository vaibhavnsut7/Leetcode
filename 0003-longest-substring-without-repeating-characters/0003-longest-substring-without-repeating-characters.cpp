class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int i=0,j=0;
        int n=s.length(); 
        int max_window_len=0;
        int window_len=0;
        int window_start=-1;
        int ans=0;
        while(j<n){
            char ch=s[j];
            while (m.count(ch) && m[ch]>=i){
                i=m[ch]+1;
                window_len=j-i;
            }
            m[ch]=j;
            window_len++;
            j++;
            if (window_len>max_window_len){
                max_window_len=window_len;
                window_start=i;
            }
        }
        // cout<<s.substr(window_start,max_window_len)<<endl;;
        return max_window_len;    
    }
};