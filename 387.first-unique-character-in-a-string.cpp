/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hashmap;
        for(int i =0; i<s.size(); i++){
            if(hashmap.count(s[i])>0){
                hashmap[s[i]] = hashmap[s[i]] + 1;
            }
            else{
                hashmap.insert(make_pair(s[i],1));
            }
        }

        for(int i =0; i<s.size(); i++){
            if(hashmap[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end

