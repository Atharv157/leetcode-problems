/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
    
private:
   vector<int> answer{1,1};
   vector<int> temp;
public:
     vector<int> getRow(int rowIndex) {
        vector<int> vector1{1};
        vector<int> vector2{1,1};
        if(rowIndex == 0) return vector1;
        else if(rowIndex == 1) return vector2;
        
        else if(answer.size()==rowIndex+1) return answer;

        temp.clear();
        temp.push_back(1);
        
        int prev = 0, next = 1;
        
        while(next < answer.size()){
            temp.push_back(answer[prev]+answer[next]);
            prev++;
            next++;
        }
        temp.push_back(1);
        answer = temp;
        
        getRow(rowIndex);
        
        return answer;
    }
};
// @lc code=end

