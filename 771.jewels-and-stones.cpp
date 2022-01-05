/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> hashset;
        int count = 0;
        for (int i = 0; i < jewels.size(); i++)
        {
            hashset.insert(jewels[i]);
        }
        for (int i = 0; i < stones.size(); i++)
        {
            /* code */
            if(hashset.count(stones[i])){
                count++;
            }
        }
        
        return count;
    }
};
// @lc code=end

