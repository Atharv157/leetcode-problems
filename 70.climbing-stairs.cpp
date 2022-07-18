/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
private:
    unordered_map<int,int> hashmap;
public:
    int climbStairs(int n) {
        if(n==0 || n== 1) return 1;
        else if(hashmap[n]) return hashmap[n];
        
        return hashmap[n] = climbStairs(n-1)+climbStairs(n-2);
        
    }
};
// @lc code=end

