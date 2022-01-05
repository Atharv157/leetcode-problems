/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    unordered_set<string> hashset;
    unordered_map<string,TreeNode*> hashanswer; 
    string serializetostr(TreeNode *root){
        if(root == nullptr)
            return "X";
        else{
            string ans = to_string(root->val)+'-'+serializetostr(root->left)+'-'+serializetostr(root->right);
            if(hashset.count(ans)>0){
                if(hashanswer.count(ans)<=0){
                    hashanswer.insert(make_pair(ans,root));
                }
            }
            else{
            hashset.insert(ans);
            }
            return ans;
        }
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> answer;
        serializetostr(root);
        for(auto it = hashanswer.begin(); it != hashanswer.end(); it++){
            answer.push_back(it->second);
        }

        return answer;
    }
};
// @lc code=end

