/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> hashset;
        string r,c,gr;
        int grid; 
        for(int row = 0; row<9; row++){
            for(int col = 0; col<9; col++){
                if(board[row][col]=='.')
                    continue;
                grid = (row/3)*3+(col/3);
                r = "r"+to_string(row)+to_string(board[row][col]);
                c = "c"+to_string(col)+to_string(board[row][col]);
                gr = "g"+to_string(grid)+to_string(board[row][col]);
                
                if(hashset.count(r)>0 ||hashset.count(c)>0 || hashset.count(gr)>0 ){
                    return false;
                }else{
                    hashset.insert(r);
                    hashset.insert(c);
                    hashset.insert(gr);
                }
                 
                }
        }
        return true;
        
    }
};
    // @lc code=end

