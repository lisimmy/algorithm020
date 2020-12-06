class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int rootIdx = 0;
        return helper(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) 
    {
        if (left > right) 
            return NULL;
        
        int pivot = left;
        while(inorder[pivot] != preorder[rootIdx]) 
            pivot++;
        
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = helper(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = helper(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
};