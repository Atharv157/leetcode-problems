/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int i =0; i<nums.size();i++){
            if(hashset.count(nums[i])>0)
                return true;
            hashset.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

