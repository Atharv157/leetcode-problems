/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> answer;
        unordered_map<string,int> hashmap;
        int min = 2001;

        for(int i= 0; i<list1.size();i++){
            hashmap.insert(make_pair(list1[i],i));
        }
        for(int j = 0; j<list2.size(); j++){
            if(hashmap.count(list2[j])>0){
                if(j+hashmap[list2[j]]<min){
                    answer.clear();
                    answer.push_back(list2[j]);
                    min = j+hashmap[list2[j]];
                }else{
                    if(j+hashmap[list2[j]]==min){
                        answer.push_back(list2[j]);
                    }
                }
            }
        }
        return answer;
    }
};
// @lc code=end

