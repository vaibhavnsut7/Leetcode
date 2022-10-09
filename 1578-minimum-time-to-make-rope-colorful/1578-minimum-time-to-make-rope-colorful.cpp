class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        char prev='#';
        int valprev=0;
        int ans=0;
        for (int i=0;i<colors.length();i++){
            if (colors[i]==prev){
                if (valprev<time[i]){
                    ans+=valprev;
                    valprev=time[i];
                }
                else{
                    ans+=time[i];
                }
            }
            else{
                prev=colors[i];
                valprev=time[i];
            }
        }
        return ans;
    }
};