class Solution {
public:
int fun(int i ,int j, int n ,int m , vector<vector<int>>&dp){
    if(i==m-1 && j== n-1) return 1;
    if(i<0 || i>m|| j<0||j>n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]= fun(i+1,j,n,m,dp)+ fun(i,j+1,n,m,dp);
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans= fun(0,0,n,m,dp);
        return ans;
        
    }
};