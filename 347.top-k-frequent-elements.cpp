/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        int temp = 0;
        unordered_map<int,int> hashmap;
        unordered_map<int,vector<int>> mp;
        // inserting element:frequency into the hashmap
        for(auto i:nums){
            if(hashmap.count(i))
                hashmap[i]++;
            else
                hashmap.insert(make_pair(i,1));
        }

        // populating mp with <count,<vector of elements>>
        for(auto it = hashmap.begin(); it != hashmap.end(); it++){
            mp[it->second].push_back(it->first);
        }
        hashmap.clear();
        // getting top k elements with most frequency
        int i = nums.size();
        while(i>0){
            // check if k elements are extracted
            if(temp == k)
                break;
            // key present
            if(mp.count(i)){
                // key present also vector is not empty
                if(mp[i].size()>0){
                    auto iter = mp[i].end(); 
                    iter--;
                    answer.push_back(*iter);
                    mp[i].pop_back();
                    temp++;
                }
                // key present but vector is empty
                else{
                    i--;
                }
            }
            // key absent
            else{
                i--;
            }
        }
        
        return answer;
    }
};
// @lc code=end

