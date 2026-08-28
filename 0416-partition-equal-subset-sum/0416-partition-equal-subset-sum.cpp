class Solution {
public:
bool fun(vector<int>& nums, int n , int i, int s1, vector<vector<int>>&dp){
    if(i==n){
        if(s1==0) return true;
    return false;

    }
    
    if(dp[i][s1]!=-1) return dp[i][s1];
    if(nums[i]>s1) return dp[i][s1]= fun(nums,n,i+1,s1,dp);
    bool c1=fun(nums,n,i+1,s1-nums[i],dp);
    bool c2= fun(nums,n,i+1,s1,dp);
    return dp[i][s1]=c1||c2;

}
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int ts=0;
        for(auto i:nums){
            ts+=i;
        }
        if(ts%2!=0) return false;
        int s1= ts/2;
        vector<vector<int>>dp(n+1,vector<int>(s1+1,-1));
        return fun(nums,n,0,s1,dp);
        
    }
};