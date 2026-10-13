class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right= height.size()-1;
        int res=0;
        while(left<right){
            int ans= min(height[left],height[right])*(right-left);
            res=max(res,ans);
            if(height[left]<height[right]){
                left++;
            } else{
                right--;
            }

        }
        return res;
        
    }
};