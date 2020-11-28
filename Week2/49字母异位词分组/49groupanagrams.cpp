// 两个map，
//  一个是 multimap, 用于存放每个排序好的字符串的下标
// 一个是 unordered_map 存放 每个排序好的字符串出现的次数

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<string> temp = strs;
        unordered_map<string, int> mpCount;
        multimap<string, int> mpIndex;

        vector<vector<string>> ret;
        vector<string> vcts;

        for (int i = 0; i < temp.size(); ++i)
        {
            sort(temp[i].begin(), temp[i].end());
            mpCount[temp[i]]++;
            mpIndex.insert(pair<string,int>(temp[i], i));
        }

        for(auto m : mpCount)
        {
            for (int i = 0; i < m.second; ++i)
            {
                auto it = mpIndex.find(m.first);
                vcts.push_back(strs[it->second]);
                mpIndex.erase(it);
            }
            ret.push_back(vcts);
            vcts.clear();
        }

        return ret;
    }
};
