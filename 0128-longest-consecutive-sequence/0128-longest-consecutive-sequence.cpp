class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int lon=0;
        for(int nu:st){
            if(st.find(nu-1)==st.end()){
                int curr=nu;
                int l=1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    l++;
                }
                lon= max(l,lon);
            }
        }
        return lon;
        
    }
};