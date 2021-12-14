/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_set<int> hashset1;
        unordered_set<int> hashset2;
        
        for(int i=0;i<nums1.size();i++){
            hashset1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            hashset2.insert(nums2[i]);
        }
        if(hashset1.size()<hashset2.size()){
            for(auto it = hashset1.begin(); it!= hashset1.end(); ++it){
                if(hashset2.count(*it)>0){
                    answer.push_back(*it);
                }
            }            
        }
        else{
            for(auto it = hashset2.begin(); it!= hashset2.end(); ++it){
                if(hashset1.count(*it)>0){
                    answer.push_back(*it);
                }
            }         
            
        }
        
        return answer;
    }
};
// @lc code=end

