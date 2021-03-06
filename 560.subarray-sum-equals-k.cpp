/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
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

