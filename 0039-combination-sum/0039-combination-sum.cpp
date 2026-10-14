class Solution {
public:
    void fun(int i, vector<int>& candidates, int target,
             vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (i == candidates.size() || target < 0) {
            return;
        }

        // Pick
        temp.push_back(candidates[i]);
        fun(i, candidates, target - candidates[i], temp, ans);

        // Backtrack
        temp.pop_back();

        // Not Pick
        fun(i + 1, candidates, target, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        fun(0, candidates, target, temp, ans);

        return ans;
    }
};