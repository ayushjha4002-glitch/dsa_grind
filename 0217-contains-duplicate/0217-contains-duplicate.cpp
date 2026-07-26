class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>pq;
        bool ans= false;
        for(auto i:nums){
            pq[i]++;
        }
        for(auto i: pq){
            if(i.second >1) return true;
            
        }
        return false;
        
        
    }
};