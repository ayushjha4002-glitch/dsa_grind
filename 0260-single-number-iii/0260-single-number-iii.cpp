class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xoor = 0;

        for(int i : nums){
            xoor ^= i;
        }

        unsigned int diff = (unsigned int)xoor & (-(unsigned int)xoor);

        int a = 0, b = 0;

        for(int j : nums){

            if(j & diff)
                a ^= j;
            else
                b ^= j;
        }

        return {a,b};
    }
};