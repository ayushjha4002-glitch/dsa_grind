class Solution {
public:
bool fun(string& s, int n  , int i , unordered_set<string>&st, vector<int>& dp){
    if (i==n) return true;
    if(dp[i]!=-1) return dp[i];
    for(int j=i;j<n;j++){
        string tmp= s.substr(i,j-i+1);
        if(st.find(tmp)!=st.end()){
            if(fun(s,n,j+1,st,dp)){
                return dp[i]= true;
            }
        }
    }
    return dp[i]= false;

}
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.size();
        unordered_set<string>st;
        for(auto word: wordDict){
            st.insert(word);
        }
        vector<int>dp(n,-1);
        return fun(s,n,0,st,dp);
        
    }
};