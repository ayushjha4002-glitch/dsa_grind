class Solution {
public:

int fun(int i,int n,unordered_map<int,int>& dp){
    if(i==n) return 1;
    if(i>n) return 0;
    if(dp.find(i)!=dp.end()){
        return dp[i];

    }
    return dp[i]=fun(i+1,n,dp) + fun(i+2,n,dp);

}
    int climbStairs(int n) {
        unordered_map<int,int>dp;
       int ans=fun(0,n,dp);
        return ans;
    

        
        
    }
};