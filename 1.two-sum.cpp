/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> hashset;
        unordered_map<int,int> hashmap;
        vector<int> answer;
        for(int i = 0; i<nums.size(); i++){
            hashset.insert(nums[i]);
        }
        for(int i = 0; i<nums.size(); i++){ 
            if(hashset.count(target - nums[i])>0 ){
                for(int j = i+1; j<nums.size(); j++){
                    if(nums[j]==target-nums[i]){
                        answer.push_back(j);
                        answer.push_back(i);
                        if(answer.size()>2){
                            for(auto it = answer.begin();it!=answer.end();it++){
                                if(*it == 0){
                                    answer.erase(it);
                                }
                                
                            }
                             
                        }
                        return answer;
                    }
                }
            }
        } 
        return answer;
    }
};
// @lc code=end

