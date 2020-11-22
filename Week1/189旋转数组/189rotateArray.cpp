class Solution
{
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // 翻转 n + 1 与 翻转1 等价
        if(k > n)
        {
            k = k % n;
        }

        for (int i = 0; i < n / 2; ++i) {
            int temp = nums[i];
            nums[i] = nums[n - i - 1];
            nums[n - i - 1] = temp;
        }
        for(int i = 0; i < k / 2; ++i)
        {
            int temp = nums[i];
            nums[i] = nums[k - i - 1];
            nums[k - i - 1] = temp;
        }

        for(int i = k, j = 0; i < k + (n - k) / 2; ++i, ++j)
        {
            int temp = nums[i];
            nums[i] = nums[n - j - 1];
            nums[n - j - 1] = temp;
        }

    }
};
