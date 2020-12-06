class Solution {
public:
    TreeNode * dfsTraverse(TreeNode * root, TreeNode * p , TreeNode * q)
    {
        // 终止
        if( root == p || root == q || root == NULL)
            return root;
        
        // 下探递归调用
        TreeNode * parentleft = dfsTraverse(root->left, p, q);
        TreeNode * parentright = dfsTraverse(root->right, p, q);
        if( parentleft && parentleft)
            return root;
        else
            return parentleft ? parentleft : parentleft;
    }
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
    {
        return dfsTraverse(root, p, q);
    }
};