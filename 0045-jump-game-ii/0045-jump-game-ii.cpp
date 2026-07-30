class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int curr=0;
        int maxx=0;
        for(int i=0;i<nums.size()-1;i++){
            maxx=max(maxx, nums[i]+i);
            if(i==curr){
                jump++;
                curr=maxx;
            }

        }
        return jump;
        
    }
};