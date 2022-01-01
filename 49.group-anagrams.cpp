/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string,vector<string>> hashmap;
        vector<string> temp;
        
        for(int i= 0; i<strs.size(); i++){
            string s;
            s = strs[i];
            sort(s.begin(),s.end());
            if(hashmap.count(s)>0){
                hashmap[s].push_back(strs[i]);
            }else{
                temp.clear();
                temp.push_back(strs[i]);
                hashmap.insert(make_pair(s,temp));
            }
        }
        for(auto it = hashmap.begin(); it!= hashmap.end(); it++){
            answer.push_back(it->second);
        }

        return answer;
    }
};
// @lc code=end

