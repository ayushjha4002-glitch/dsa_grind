class Solution {
public:
int fun(int i, int n, vector<int>&nums, unordered_map<int,int>&dp){
    if(i>=n) return 0;
    if(dp.find(i)!=dp.end()){
        return dp[i];

    }
    int c=nums[i]+fun(i+2,n,nums,dp);
    int c1=fun(i+1,n,nums,dp);
    return dp[i]= max(c,c1);
}
    int rob(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>dp;
        int ans= fun(0,n,nums,dp);
        return ans;
        
    }
};