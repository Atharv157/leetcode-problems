/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<string>&answer,unordered_map<string,multiset<string>>&hashmap,string node){
       while(hashmap[node].size()){
           string first = *hashmap[node].begin();
           hashmap[node].erase(hashmap[node].begin());
           dfs(answer,hashmap,first);
       } 
        
        answer.push_back(node);
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> hashmap;
//         representing the graph via hashmap,using the multiset keeps it sorted when new elements are inserted
        for(auto var:tickets)
            hashmap[var[0]].insert(var[1]);
        
        vector<string>answer;
        dfs(answer,hashmap,"JFK");
        
        reverse(answer.begin(),answer.end());
        return answer;
        
    }
};
// @lc code=end

