

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 二进制中有且只有1 个 1
        if (n > 0 && (n & (n - 1)) == 0)
            return true;
        return false;
    }
};
