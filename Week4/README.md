学习笔记

搜索：
深度优先
广度优先 ： 更符合人脑的思维方式
优先级优先，启发式搜索  -- 深度学习（推荐算法）


DFS 递归写法
//C/C++
//递归写法：
map<int, int> visited;

void dfs(Node* root)
{
    // terminator
    if (!root)
        return ;

    if (visited.count(root->val))
    {
        // already visited
        return ;
    }

    visited[root->val] = 1;

    // process current node here. 
    // ...
    for (int i = 0; i < root->children.size(); ++i)
    {
        dfs(root->children[i]);
    }
    return ;
}

DFS 非递归写法
//C/C++
//非递归写法：
void dfs(Node* root) 
{
    map<int, int> visited;
    if(!root) 
        return ;
    
    stack<Node*> stackNode;
    stackNode.push(root);

    while (!stackNode.empty()) 
    {
        Node* node = stackNode.top();
        stackNode.pop();
        if (visited.count(node->val)) 
            continue;
        visited[node->val] = 1;
        
        for (int i = node->children.size() - 1; i >= 0; --i) 
        {
            stackNode.push(node->children[i]);
        }
    }

    return ;
}


BFS 模板
// C/C++
void bfs(Node* root)
{
    map<int, int> visited;
    if(!root) return ;

    queue<Node*> queueNode;
    queueNode.push(root);

    while (!queueNode.empty())
    {
        Node* node = queueNode.top();
        queueNode.pop();
        if (visited.count(node->val))
            continue;
        visited[node->val] = 1;

        for (int i = 0; i < node->children.size(); ++i)
        {
            queueNode.push(node->children[i]);
        }
    }
    return ;
}


贪心算法：

贪心算法是一种在每一步选择中都采取在当前状态下最好或最优（即最有利）的选择，从而希望导致结果是全局最好或最优的算法。

贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。

贪心：当下做局部最优判断
回溯：能够回退
动态规划：最优判断+回退


贪心法可以解決一些最优化题，如：求图中的最小生成树、求哈夫曼编码等。然而对于工程和生活中的问题，贪心法一般不能得到我们所要求的答案。

一个问题可以通过贪心法来解決，那么贪心法一般是解决这个问题的最好办法。由于贪心法的高效性以及其所求得的答案比较接近最优结果，贪心法也可以用作辅助算法或者直接解决一些要求结果不特别精确的问题。

贪心算法的场景
简单地说，问题能够分解成子问题来解决，子问题的最优解能递推到最终问题的最优解。这种子问题最优解称为最优子结构。

贪心算法与动态规划的不同在于它对每个子问题的解決方案都做出选择，不能回退。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。
