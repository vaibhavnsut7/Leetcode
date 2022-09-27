class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        set<string> st;

        stringstream ss(s);
        string word;
        while (ss>>word){
            vec.push_back(word);
        }
        
        if (pattern.length()!=vec.size()){
            return false;
        }
        unordered_map<char,string> m;
        for (int i=0;i<pattern.length();i++){
            char ch=pattern[i];
            
            if (m.find(ch)!=m.end()){
                if (m[ch]!=vec[i])
                    return false;
            }
            else{
                if (st.find(vec[i])!=st.end()){
                    return false;
                }
                m[ch]=vec[i];
                st.insert(vec[i]);
            }
        }
        return true;
        
        
    }
};