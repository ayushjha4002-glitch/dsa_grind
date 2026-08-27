class Solution {
public:
unordered_map<int,int>dp;
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        return dp[n]= fib(n-1)+ fib(n-2);

        
    }
};