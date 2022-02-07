/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution {
public:
     void dfs(int node,int destination, vector<int>&visited, unordered_map<int,vector<int>>&graph){
        visited[node] = 1;
        for(int neighbour: graph[node]){
            if(!visited[neighbour]){
                dfs(neighbour,destination,visited,graph);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         build the graph
        vector<int> visited(n,0);
        unordered_map<int,vector<int>> graph;
        for(auto arr:edges){
            graph[arr[0]].push_back(arr[1]);
            graph[arr[1]].push_back(arr[0]);
        }
        dfs(source,destination,visited,graph);
        if(visited[destination]) return true;
        else return false;
    }
};
// @lc code=end

