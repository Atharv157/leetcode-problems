/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */

// @lc code=start
class Solution {
public:
    int find(int x, vector<int>&root){
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x],root);
    
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> root;
        vector<int> rank(n,1);
        for(int i = 0; i < n; i++) root.push_back(i);
        
        for(auto &arr : pairs){
            
            int rootX = find(arr[0],root);
            int rootY = find(arr[1],root);
            
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    root[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    root[rootX] = rootY;
                } else {
                    root[rootY] = rootX;
                    rank[rootX] += 1;
                }
            }
        }
//         creating hashmap for storing the root and related vertex
        unordered_map<int,string> hashmap;
        for(int i = 0; i<n; i++){
            int var = find(i,root);
            hashmap[var] += s[i];
        }
        
//         sorting the vector so we can form smallest string
        for(auto it = hashmap.begin(); it != hashmap.end(); it++){
            sort(it->second.begin(),it->second.end(),greater<int>());
        }
        

        string ans = "";
        for(int i = 0; i < n; i++){
            int var = find(i,root);
            string &s = hashmap[var];
            ans += s[s.size() - 1];
            s.pop_back();
        }
        return ans;
    }
};
// @lc code=end

