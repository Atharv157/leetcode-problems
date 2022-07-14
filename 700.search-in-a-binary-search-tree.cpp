/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 */

// @lc code=start
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
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root == nullptr) return nullptr;
        else if(root->left == nullptr && root->right == nullptr && root->val != val) return nullptr;
        else if(root->val == val) return root;
// go left
        else if(val < root->val)
        root = searchBST(root->left,val);
            
// go right
        else
        root = searchBST(root->right,val);
        
        return root;
    }
};
// @lc code=end

