class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        
        int len=0;
        for(int i: st){
            if(st.find(i-1)==st.end()){
                int curr= i;
                int l=1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    l++;
                }
                len= max(len,l);
            }
        }
        return len;
        
    }
};