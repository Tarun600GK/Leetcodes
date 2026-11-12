
class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans = 0;

        for (int i = 0; i < 32; i++) {
            ans <<= 1;           // Shift answer left
            ans |= (n & 1);      // Copy last bit of n
            n >>= 1;             // Remove last bit of n
        }

        return ans;
    }
};
