class Solution {
public:
    int trap(vector<int>& height) {

        int m = height.size();

        vector<int> leftMax(m);
        vector<int> rightMax(m);

        leftMax[0] = height[0];

        for(int i = 1; i < m; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[m-1] = height[m-1];

        for(int i = m-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int ans = 0;

        for(int i = 0; i < m; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }
};