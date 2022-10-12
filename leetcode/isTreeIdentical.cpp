/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }
        bool same = p->val == q->val;
        bool b1 = isSameTree(p->left, q->left);
        bool b2 = isSameTree(p->right, q->right);
        return (same && b1 && b2);
        // if (p == nullptr && q == nullptr) {
        //     return true;
        // }else if (p == nullptr || q == nullptr) {
        //     return false;
        // } else {
        //     return (isSameTree )
        // }
    }
};