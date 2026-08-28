class Solution {
public:

    int fun(vector<int>& coins, int n, int i, int amount,
            vector<vector<int>>& dp) {

        if(amount == 0)
            return 0;

        if(i == n)
            return 1e9;

        if(dp[i][amount] != -1)
            return dp[i][amount];

        int c1 = 1e9;

        if(coins[i] <= amount)
            c1 = 1 + fun(coins, n, i, amount - coins[i], dp);

        int c2 = fun(coins, n, i + 1, amount, dp);

        return dp[i][amount] = min(c1, c2);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, -1)
        );

        int ans = fun(coins, n, 0, amount, dp);

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};