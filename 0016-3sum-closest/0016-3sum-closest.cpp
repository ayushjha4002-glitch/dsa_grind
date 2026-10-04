class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());   // important

        int res = nums[0] + nums[1] + nums[2];  // initial sum

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                // agar current sum target ke zyada close hai
                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                }

                if (sum < target) {
                    j++;        // sum chhota hai → badhao
                } 
                else if (sum > target) {
                    k--;        // sum bada hai → kam karo
                } 
                else {
                    return sum; // exact match mil gaya
                }
            }
        }
        return res;
    }
};
