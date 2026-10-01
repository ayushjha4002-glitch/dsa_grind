class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>pq;
        for(auto i:s){
            pq[i]++;
        }
        unordered_map<char,int>sq;
        for(auto j:t){
            sq[j]++;

        }
        if(pq==sq) return true;
        return false;
        
        
    }
};