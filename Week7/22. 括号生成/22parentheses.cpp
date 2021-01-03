class Solution 
{
public:
    vector<string> vct;
    vector<string> generateParenthesis(int n) 
    {
        string str = "";
        helper(n, n, str);

        return vct;
    }
    void helper(int left, int right, string str)
    {
        // 递归终止
        if(left == 0 && right == 0)
        {
            vct.push_back(str);
            return ;
        }

        // 下探
        if(left > 0)    // 剪枝
        {
            helper(left - 1, right, str + '(');
        }
        if(right > left)   // 剪枝
        {
            helper(left, right - 1, str + ')');
        }
    }
};