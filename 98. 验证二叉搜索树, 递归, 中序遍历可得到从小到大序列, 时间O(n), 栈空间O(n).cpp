/*
98. 验证二叉搜索树

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

--------------------------------------------------------------------
98. 验证二叉搜索树, 递归, 中序遍历可得到从小到大序列, 时间O(n), 栈空间O(n)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        bool flag = true;
        long nMax = numeric_limits<long>::min();
        inorder(root, flag, nMax);
        return flag;
    }
    
    // 二叉搜索树的中序遍历是从小到大排列的,如果有节点不满足从小到大,就输出false并退出
    void inorder(TreeNode* node, bool& flag, long& nMax) // 中序遍历
    {
        if(!node) // 是NULL节点就退出
            return;
        
        inorder(node->left, flag, nMax);
        if(node->val > nMax) // 中序时,访问根节点,干一次活
            nMax = node->val;
        else
        {
            flag = false;
            return;
        }
        inorder(node->right, flag, nMax);
    }
};
