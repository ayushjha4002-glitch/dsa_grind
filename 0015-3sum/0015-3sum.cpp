class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n-2; i++) {

            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int j = i+1;
            int k = n-1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    int left = nums[j];
                    int right = nums[k];

                    while(j < k && nums[j] == left)
                        j++;

                    while(j < k && nums[k] == right)
                        k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        return ans;
    }
};