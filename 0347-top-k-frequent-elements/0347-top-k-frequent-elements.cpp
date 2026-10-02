class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        for(auto i:nums){
            f[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto j:f){
            pq.push({j.second,j.first});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};