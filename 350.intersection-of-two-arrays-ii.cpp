/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashmap;
        
        vector<int> answer;
        for(int i = 0;i<nums1.size(); i++){
            if(hashmap.count(nums1[i])>0)
                hashmap[nums1[i]] += 1;
            else
                hashmap.insert(make_pair(nums1[i],1));
        }
        
        
        for(int k =0; k<nums2.size();k++){
            if(hashmap[nums2[k]]){
                answer.push_back(nums2[k]);
                hashmap[nums2[k]]--;
            }
        }
        
    
        return answer;
    }
};
// @lc code=end

