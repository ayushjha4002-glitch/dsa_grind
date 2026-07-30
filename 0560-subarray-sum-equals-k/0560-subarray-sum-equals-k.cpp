class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int res=0;
        unordered_map<int , int>f;
        int sum=0;
        f[sum]++;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(f.find(sum-k)!=f.end()){
                res+=f[sum-k];


            }
            f[sum]++;
        }
        return res;
    }
};