class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int windsum=0;
        int minsum= INT_MAX;
        for(int high=0;high<n;++high){
            windsum+=nums[high];
        
        while(windsum>=target){
            minsum= min(minsum,high-low+1);
            windsum-=nums[low];
            ++low;
        }
        }
        if(minsum==INT_MAX) return 0;
        return minsum;
        
    }
};