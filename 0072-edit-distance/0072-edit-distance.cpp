class Solution {
public:

    int fun(string& word1, string& word2,
            int i, int j, int n, int m,
            vector<vector<int>>& dp) {

        if(i == n)
            return m - j;

        if(j == m)
            return n - i;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j])
            return dp[i][j] = fun(word1, word2,
                                   i + 1, j + 1,
                                   n, m, dp);

        int c1 = 1 + fun(word1, word2,
                         i, j + 1,
                         n, m, dp);       // INSERT

        int c2 = 1 + fun(word1, word2,
                         i + 1, j,
                         n, m, dp);       // DELETE

        int c3 = 1 + fun(word1, word2,
                         i + 1, j + 1,
                         n, m, dp);       // REPLACE

        return dp[i][j] = min(c1, min(c2, c3));
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return fun(word1, word2, 0, 0, n, m, dp);
    }
};