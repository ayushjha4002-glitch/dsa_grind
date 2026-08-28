class Solution {
public:

    int fun(vector<int>& coins, int n, int i, int amount,
            vector<vector<int>>& dp) {

        if(amount == 0)
            return 1;

        if(i == n)
            return 0;

        if(dp[i][amount] != -1)
            return dp[i][amount];

        int c1 = 0;

        if(coins[i] <= amount)
            c1 = fun(coins, n, i, amount - coins[i], dp);

        int c2 = fun(coins, n, i + 1, amount, dp);

        return dp[i][amount] = c1 + c2;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, -1)
        );

        return fun(coins, n, 0, amount, dp);
    }
};