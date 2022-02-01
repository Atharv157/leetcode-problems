/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    int find(int x,vector<int>&root) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x],root);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> root(n,0);
        vector<int> rank(n,1);
        for(int i = 0;i<n; i++) root[i] = i;
        int count = 0;
        unordered_set<int> hashset;
        
        for(int i = 0;i<n;i++){
            for(int j = i+1; j<n; j++){
                if(isConnected[i][j] == 1){
//                     we have to create union now
                    int rootX = find(i,root);
                    int rootY = find(j,root);
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
            }
        }
        for(int i = 0; i<n; i++){
            if(hashset.count(find(i,root))<=0){
                hashset.insert(find(i,root));
                count++;
            }
            
        }
        
        return count;
    }
};
// @lc code=end

