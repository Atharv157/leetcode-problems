/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// brute force approach using hashmap
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*,Node*> hashmap;
//         hashmap.insert(make_pair(nullptr,nullptr));
//         Node *curr = head;
//         while(curr){
//             Node *newnode = new Node(curr->val);
//             hashmap.insert(make_pair(curr,newnode));
//             curr = curr->next;
//         }
        
//         Node *copyhead = hashmap[head];
//         Node *newnode;
//         curr = head;
//         while(curr){
//             newnode = hashmap[curr];
//             newnode->next = hashmap[curr->next];
//             newnode->random = hashmap[curr->random];
//             curr = curr->next;
//         }
//         return copyhead;
        
//     }

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
       Node *curr = head;
//         inserting deep copy nodes in between original list
        while(curr){
            Node *copynode = new Node(curr->val);
            copynode->next = curr->next;
            curr->next = copynode;
            curr = copynode->next;
        }
//         now establish random pointers of deep copy nodes 
        curr = head;
        while(curr){
            Node *random = curr->random;
            if(random) curr->next->random = random->next;
            else curr->next->random = nullptr;
            curr = curr->next->next;
        }
//         separating the nodes of orig list and deep copy list so that original structure as well as copy list is generated
        Node *copyhead = head->next;
        Node *copy = copyhead;
        Node *orig = head;
        while(orig){
            orig->next = copy->next;
            if(orig->next)copy->next = orig->next->next;
            else copy->next = orig->next;
            copy = copy->next;
            orig = orig->next;
        }
        return copyhead;
    }
};
// @lc code=end

