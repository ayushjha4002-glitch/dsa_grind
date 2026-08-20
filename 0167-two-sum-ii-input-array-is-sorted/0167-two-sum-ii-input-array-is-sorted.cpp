class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        int low=0,right= n-1;
        for(int k=0;k<n;k++){
            int sum= numbers[low]+ numbers[right];
            if(sum==target){
                return {low+1,right+1};
            } else if(sum>target){
                right--;
            } else{
                low++;
            }

        }
        return {low+1,right+1};
        
        
    }
};