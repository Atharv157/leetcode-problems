/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }else{
            unordered_map<char,char> hashmap;
            for(int i = 0; i<s.size();i++){
                if(hashmap.count(s[i])>0){
                    if(hashmap[s[i]]!=t[i])
                        return false;
                }
                else{
                
                // check t[i] for being present in vals of hashmap
                for(auto it = hashmap.begin();it!=hashmap.end();it++){
                    if(t[i] == it->second){
                        if(it->first != s[i]){
                            return false;
                        }
                    }
                }

                hashmap.insert(make_pair(s[i],t[i]));
                }
            }
        }
        return true;
    }
    
};
// @lc code=end

