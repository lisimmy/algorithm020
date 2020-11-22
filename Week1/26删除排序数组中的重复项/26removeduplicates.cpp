class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        int swapindex = 0;
        if(n == 0)
        {
            return 0;
        }

        for(int i = 1; i < n; ++i)
        {
            if(nums[i] != nums[swapindex])
            {
                ++swapindex;
                nums[swapindex] = nums[i];
            }
        }
        nums.erase(nums.begin() + swapindex + 1, nums.end());
        return nums.size();
    }
};
