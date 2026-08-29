class Solution {
public:
int fun(int i,int j ,int n,int m, vector<vector<int>>&dp,vector<vector<int>>&grid){
    if(i==n-1 && j==m-1) return grid[i][j];
    if(i>=n ||  j>=m) return 1e8;
    if(dp[i][j]!=-1) return dp[i][j];
    int c1= grid[i][j]+ fun(i+1,j,n,m,dp,grid);
    int c2= grid[i][j]+ fun(i,j+1,n,m,dp,grid);
    return dp[i][j]= min(c1,c2);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans= fun(0,0,n,m,dp,grid);
        return ans;

        
    }
};