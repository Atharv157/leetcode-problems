/*
 * @lc app=leetcode id=136 lang=cpp
 *git
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int i=0;i<nums.size();i++){
            if(hashset.count(nums[i])>0)
                hashset.erase(nums[i]);
            else
                hashset.insert(nums[i]);
        }
        
        return *hashset.begin();
    }
};
// @lc code=end

