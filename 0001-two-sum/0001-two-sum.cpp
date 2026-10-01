class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n= nums.size();
        int i=0,j= n-1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                return{i,j};
            }
            else if(nums[i]+nums[j]<target){
                i++;
            } else{
                j--;
            }
        }
        return {i,j};
        
    }
};