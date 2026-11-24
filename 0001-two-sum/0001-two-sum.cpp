class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        unordered_map<int,int>f;
        for(int i=0;i<n;i++){
            int rem = target- nums[i];
            if(f.find(rem)!=f.end()){
                return{f[rem],i};

            }
            f[nums[i]]=i;
        }
        return{};
    }
};