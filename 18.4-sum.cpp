/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        if(nums.size()<4)
            return answer;
        set<vector<int>> hashset;
        sort(nums.begin(),nums.end());
        int left,right;
        long long int sum;
        for(int i = 0; i<nums.size()-3; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for( int j = i+1; j<nums.size()-2; j++){
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                left = j+1;
                right = nums.size()-1;
                while(left<right){
                    long long int a = nums[i];
                    long long int b = nums[j];
                    long long int c = nums[left];
                    long long int d = nums[right];
                    sum = a+b+c+d;
                    if(sum>target)
                        right--;
                    else if(sum<target)
                        left++;
                    else{
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        hashset.insert(temp);
                        temp.clear();
                        left++;
                    }
                }
            }
    
        }
        
        for(auto item:hashset){
            answer.push_back(item);
        }
        return answer;
    }
};
// @lc code=end

