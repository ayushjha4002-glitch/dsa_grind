class Solution {
public:
    void fun(int i, vector<int>& candidates, int target,
             vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (i == candidates.size() || target < 0)
            return;

        // Pick
        temp.push_back(candidates[i]);
        fun(i + 1, candidates, target - candidates[i], temp, ans);

        // Backtrack
        temp.pop_back();

        // Skip duplicates
        while (i + 1 < candidates.size() &&
               candidates[i] == candidates[i + 1]) {
            i++;
        }

        // Not Pick
        fun(i + 1, candidates, target, temp, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        vector<vector<int>> ans;

        fun(0, candidates, target, temp, ans);

        return ans;
    }
};