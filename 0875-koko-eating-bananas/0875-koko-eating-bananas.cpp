class Solution {
public:
    long long fun(vector<int>& piles, int guess) {
        long long times = 0;

        for(auto i : piles) {
            times += i / guess;

            if(i % guess != 0) {
                times++;
            }
        }

        return times;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int res = -1;

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int guess = low + (high - low) / 2;

            long long tin = fun(piles, guess);

            if(tin > h) {
                low = guess + 1;
            }
            else {
                res = guess;
                high = guess - 1;
            }
        }

        return res;
    }
};