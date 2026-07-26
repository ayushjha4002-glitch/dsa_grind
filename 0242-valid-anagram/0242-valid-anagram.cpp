class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()) return false;
        unordered_map<char,int>pq;
        for(auto i: s){
            pq[i]++;
        }
        unordered_map<char,int> f;
        for(auto i:t){
            f[i]++;
        }
        if(pq==f) return true;
        return false;
        
    }
};