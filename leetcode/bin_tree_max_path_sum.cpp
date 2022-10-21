//  Definition for a binary tree node.

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int highest;
    int negativeHighest;
    int negativeCount;
    int nodeCount;
    Solution()
    {
        highest = -INT_MAX;
        negativeHighest = -INT_MAX;
        negativeCount = 0;
        nodeCount = 0;
    }

    int f(TreeNode *node)
    {

        if (node == nullptr)
            return 0;
        nodeCount++;

        if (node->val < 0)
        {
            negativeCount++;
            if (node->val > negativeHighest)
            {
                negativeHighest = node->val;
            }
        }
        // if (node->val > highest)
        // {
        //     highest = node->val;
        // }
        if (node->left == nullptr && node->right == nullptr)
        {

            return node->val;
        }
        int lSum = f(node->left);
        // lSum = lSum > 0 ? lSum : 0;
        int rSum = f(node->right);
        // rSum = rSum > 0 ? rSum : 0;
        if (node->val + lSum + rSum > highest)
        {
            highest = node->val + lSum + rSum;
        }

        if (node->val < 0)
        {
            if (max(lSum, rSum) > highest)
            {
                highest = max(lSum, rSum);
            }
        }

        return (max(lSum, rSum) + node->val);
        // return (max(lSum, rSum) + node->val > 0 ? max(lSum, rSum) + node->val : highest);
        // return (max(lSum, rSum) + node->val > 0 ? max(lSum, rSum) + node->val : 0);
    }
    int maxPathSum(TreeNode *root)
    {
        if (negativeCount == nodeCount)
        {
            return negativeCount;
        }
        int mMax = f(root);
        // mMax = max(mMax, negativeHighest);
        return max(mMax, highest);
        // return max(mMax, highest);
    }
};