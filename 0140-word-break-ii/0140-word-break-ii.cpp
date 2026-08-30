class Solution {
public:
vector<string> fun(string& s, int n,int i,unordered_set<string>& st, vector<vector<string>>&dp){
    if(i==n) return {""};
    if(!dp[i].empty()) return dp[i];
    vector<string>ans;
    for(int j=i;j<n;j++){
        string tmp= s.substr(i,j-i+1);
        if(st.find(tmp)!=st.end()){
            vector<string>rem= fun(s,n,j+1,st,dp);
            for(auto x: rem){
                if(x==""){
                    ans.push_back(tmp);
                } else{
                    ans.push_back(tmp+ " "+x);
                }
            } 
        }
    }
    return dp[i]=ans;
}

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n= s.size();
        unordered_set<string>st;
        for(auto word:wordDict){
            st.insert(word);
        }
        vector<vector<string>>dp(n);
        return fun(s,n,0,st,dp);
        
    }
};