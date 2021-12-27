/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashset;
        
        
        while(1){
        int digit;int newnum=0;
       while(n>0){
           digit = n%10;
           n = n/10;
           newnum += digit*digit;
       }
            if(newnum==1){
                return true;
            }else{
                if(hashset.count(newnum)>0){
                    return false;
                }
                hashset.insert(newnum);
                n = newnum;
            }
        }
    }
};
// @lc code=end

