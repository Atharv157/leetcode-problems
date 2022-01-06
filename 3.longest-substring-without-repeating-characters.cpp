/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        unordered_map<char,char> hashmap;
        int left = 0, right = 0;
        if(s.size()<=0){
            return max;
        }
        while(right<=s.size()-1){
            if(hashmap.count(s[right])>0){
                hashmap.erase(s[left]);
                left++;
            }else{
                hashmap.insert(make_pair(s[right],' '));
                if(right-left+1>max){
                    max = right-left+1;
                }
                right++;
            }
    
        }
        return max;
    }

};
// @lc code=end

