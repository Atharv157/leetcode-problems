/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
    
private:
    unordered_map<string,int> hashmap;
    int findValueRecursively(int row, int col){
        string key = to_string(row)+"_"+to_string(col);
        if(row<=1 || col == 0 || col == row)
            return 1;
        else{
//             if key exists then return that val
            if(hashmap.count(key))
                return hashmap[key];
// if key doesnt exist then calculate and add in the hashmap
            int calc = findValueRecursively(row-1,col-1)+findValueRecursively(row-1,col); 
            hashmap.insert(make_pair(key,calc));
            return calc;  
        }
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vect1{1};
        vector<int> vect2{1,1};
        if(rowIndex == 0) return vect1;
        if(rowIndex == 1) return vect2;
            
        
        vector<int> answer;
        answer.push_back(1);
        for(int col = 1; col<=rowIndex/2; col++){
            answer.push_back(findValueRecursively(rowIndex,col));
        }
        
        for(int i = answer.size() - 1; i >= 0; i--){
            if(i == answer.size()-1 and rowIndex%2 == 0) continue;
            else answer.push_back(answer[i]);
        }
        // answer.push_back(1);
        
        return answer;
    }
};
// @lc code=end

