/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
private:
    unordered_map<string,double> hashmap;
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        else if(n==0) return 1;
        else if(n == 1) return x;
        else if(n == -1) return 1/x;
        
        
        string str = to_string(x)+"_"+to_string(n);
        if(hashmap[str]) return hashmap[str];
        
        int half = n/2;
        double a = myPow(x,half);
        if(a == 0) return 0;
        double b = myPow(x,n-half);
        return hashmap[str] = a*b;

    }
};
// @lc code=end

