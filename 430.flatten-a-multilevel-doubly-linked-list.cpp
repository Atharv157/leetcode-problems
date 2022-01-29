/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *flatten_recursion(Node *head){
        Node *curr = head;
        Node *tail = head;
        Node *next;
        Node *child;
        while(curr){
            next = curr->next;
            child = curr->child;
            if(child){
                Node *pseudotail = flatten_recursion(child);
                pseudotail->next = next;
                if(next) next->prev = pseudotail;
                
                curr->next = child;
                child->prev = curr;
                curr->child =nullptr;
                
                curr = pseudotail;
            }
            else 
                curr = next;
            if(curr) tail = curr;
            
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if(!head) return head;
        flatten_recursion(head);
        return head;
    }
};

// @lc code=end

