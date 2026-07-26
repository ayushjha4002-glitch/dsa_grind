class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            ans = ans << 1;      // Make space for next bit
            ans |= (n & 1);      // Put last bit of n
            n = n >> 1;          // Remove last bit
        }

        return ans;
    }
};