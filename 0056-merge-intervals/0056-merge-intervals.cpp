class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        if (intervals.size()==0) return res;
        int start= intervals[0][0];
        int end= intervals[0][1];
        for (int i=1 ; i<intervals.size();i++){
            int currst= intervals[i][0];
            int  curren= intervals[i][1];
            if(currst<= end){
                end=max(end,curren);
            } else{
                res.push_back({start,end});
            start=currst;
            end=curren;

            }
            

        }
        res.push_back({start,end});
        return res;
        
    }
};