/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *node,vector<int>&visited,unordered_map<Node*,Node*>&hashmap){
        visited[node->val] = 1;
        Node *newnode = new Node(node->val);
        hashmap[node] = newnode;
        for(auto neighbor:node->neighbors){
            if(!visited[neighbor->val]){
                dfs(neighbor,visited,hashmap);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        vector<int>visited(101,0);
        unordered_map<Node*,Node*>hashmap;
        dfs(node,visited,hashmap);
        vector<Node*> temp;
        for(auto it = hashmap.begin();it!=hashmap.end();it++){
            for(auto var:it->first->neighbors){
                temp.push_back(hashmap[var]);
            }
            it->second->neighbors = temp;
            temp.clear();
        }
        
        return hashmap[node];

    }
};
// @lc code=end

