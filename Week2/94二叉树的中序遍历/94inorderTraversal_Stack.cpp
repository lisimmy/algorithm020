class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) 
        {
            // root和所有的左孩子入栈
            while (root != nullptr) 
            {
                stk.push(root);
                root = root->left;
            }
            // 最后一个左孩子弹出，作为一个新的root
            // 下一步遍历右孩子，右孩子作为下一次循环的root（右孩子也可能有左孩子）
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            // 弹出结点的第一个右孩子先入栈，该右孩子的所有的左孩子依次入栈
            root = root->right;
        }
        return res;
    }
};
