/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
//     temp is used for storing the sequence
//     and then temp is pushed into answer which is final return value
    void dfs(int node,int destination, vector<int>&visited, vector<vector<int>>&answer,vector<int>&temp,vector<vector<int>>&graph){
//         if destination is reached then set visited to 0 and pop the sequence from temp
        if(node == destination){
            visited[node] = 0;
            temp.push_back(destination);
            answer.push_back(temp);
            temp.pop_back();
            return;
        }
        visited[node] = 1;
        temp.push_back(node);
        for(auto neighbour:graph[node]){
            if(!visited[neighbour])
                dfs(neighbour,destination,visited,answer,temp,graph);
        }
        visited[node] = 0;
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int source = 0;
        int destination = graph.size()-1;
        vector<int> visited(graph.size(),0);
        vector<int>temp;
        vector<vector<int>> answer;
        dfs(source,destination,visited,answer,temp,graph);
        return answer;
    }
};
// @lc code=end

