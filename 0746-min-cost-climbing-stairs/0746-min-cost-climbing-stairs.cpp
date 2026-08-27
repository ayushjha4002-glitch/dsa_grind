class Solution {
public:
int fun(int i, int n , vector<int>&cost, unordered_map<int,int>&dp){
    if(i>=n) return 0;
    if(dp.find(i)!= dp.end()){
        return dp[i];
    }
    int c1= fun(i+1,n,cost,dp);
    int c2= fun(i+2,n,cost,dp);
    return dp[i]= cost[i]+min(c1,c2);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        unordered_map<int,int>dp;
        int res= min(fun(0,n,cost,dp),fun(1,n,cost,dp));
        return res;
        
    }
};