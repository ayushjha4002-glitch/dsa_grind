class Solution {
public:
int fun(int i, int n, vector<int>&nums , unordered_map<int,int>&dp){
    if(i==n) return 0;
    if(i>n) return 0;
    if(dp.find(i)!= dp.end()){
        return dp[i];
    }
    int c1= nums[i]+fun(i+2,n,nums,dp);
    int c2= fun(i+1,n,nums,dp);
    return dp[i]= max(c1,c2);
}
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        unordered_map<int,int>dp;
        unordered_map<int,int>dp1;
        int ans=max(fun(0,n-1,nums,dp),fun(1,n,nums,dp1));
        return ans;
        
    }
};