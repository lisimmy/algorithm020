class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
            return false;

        map<int,int> sumChar;
        for(auto ch : s)
            sumChar[ch]++;

        for(auto ch : t)
            sumChar[ch]--;
        for(auto it = sumChar.begin(); it != sumChar.end(); ++it)
        {
            if(it->second != 0)
                return false;
        }

        return true;
    }
};
