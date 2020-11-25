class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        accessAsRoot(root, ret);
        return ret;
    }
    void accessAsRoot(TreeNode* root, vector<int>& ret)
    {
        if(root == nullptr)
            return;
        accessAsRoot(root->left, ret);
        ret.push_back(root->val);
        accessAsRoot(root->right, ret);
    }
};
