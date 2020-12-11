class Solution 
{
public:
    // 比较两个字符串， 如果只有一个字符有差异，返回真
    bool oneChDiff(string& src, string& dest)
    {
        int n = src.size();
        int diffCount = 0;
        for(int i = 0; i < n; ++i)
        {
            if(src[i] != dest[i])
                ++diffCount;
            if(diffCount > 1)
                return false;
        }
        return diffCount == 1? true : false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set <string>  uset(wordList.begin(), wordList.end());
        unordered_set <string> visited;
        if(beginWord == endWord && uset.find(endWord) != uset.end())
            return 0;
        if(uset.find(endWord) == uset.end())
            return 0;

        int count = 0;
        queue<string> qu;

        qu.push(beginWord);
        ++count;   // beginWord算一次
        while(!qu.empty())
        {
            int quSize = qu.size();
            // 从字典中找出与quStr只差一个字符的单词
            for(int i = 1; i <= quSize; ++i)
            {
                string quStr = qu.front();
                qu.pop();
                for(auto it : uset)
                {
                    if(oneChDiff(quStr, it) && visited.find(it) == visited.end())
                    {
                        qu.push(it);
                        visited.insert(it);
                        if(endWord == it)
                            return ++count;
                        //uset.erase(it);
                    }
                }
            }
            ++count;
            if(count > wordList.size())
                return 0;
        }
        return 0;
    }
};