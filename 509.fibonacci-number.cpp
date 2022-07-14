/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
private:
    unordered_map<int,int> hashmap;
public:
    int fib(int n) {
        int answer;
        
        if(n == 0) return 0;
        else if(n == 1 || n == 2) return 1;
        
        else{
            if(hashmap.count(n)) return hashmap[n]; 
            
            answer = fib(n-1)+fib(n-2);
            hashmap[n] = answer;
            return answer;
        }
        
       return answer; 
    }
};
// @lc code=end

