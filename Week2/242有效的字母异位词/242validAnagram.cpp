class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
            return false;

        map<int,int> sumChar;
        for(auto ch : s)
        {
            sumChar[ch]++;
        }

        for(auto ch : t)
        {
            sumChar[ch]--;
            if(sumChar[ch] < 0)
                return false;
        }

        return true;
    }
};
