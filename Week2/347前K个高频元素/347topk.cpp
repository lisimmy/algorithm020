class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int,int> hashMap;
        vector<int> vct;

        // 小顶堆， 结点时pair， pair重载了比较运算符，可以比较pair的大小
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        for(auto c : nums)
            hashMap[c]++;
        
        for(auto pairval : hashMap)
        {
            // 入队列 （维护一个只有K个结点的小顶堆）
            q.push(pair(pairval.second, pairval.first));
            if(q.size() > k)   // 小顶堆中大于K个pair，就弹出最小的
                q.pop();
        }
        while(!q.empty())
        {
            vct.push_back(q.top().second);
            q.pop();
        }

        return vct;
    }
};
