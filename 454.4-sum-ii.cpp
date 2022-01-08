/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> hashmap;
        int count = 0;
        // created a hashmap to store all possible sums of
        //  elements of nums 1 and nums2 
        // eg: (sum:frequency)
        for(auto n1:nums1){
            for(auto n2:nums2){
                if(hashmap.count(n1+n2)){
                    hashmap[n1+n2]++;
                }
                else{
                    hashmap.insert(make_pair(n1+n2,1));
                }

            }
        }

        // now loop through nums3 and nums4 and check for availability of -(n3+n4) in the hashset
        // if yes then increment count by hashmap[val]
        for(auto n3:nums3){
            for(auto n4:nums4){
                if(hashmap.count(-(n3+n4))>0){
                    count+=hashmap[-(n3+n4)];
                }
            }
        }
        hashmap.clear();
        return count;
    }
};
// @lc code=end

