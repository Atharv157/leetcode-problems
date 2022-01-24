/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
//         creating a dummy node pointing to head
        ListNode *node = new ListNode();
        node->next = head;
        
        ListNode *ahead = node;
        ListNode *behind = node;
//         moving the ahead node n times
        for(int i = 0;i<n; i++){
            ahead = ahead->next;
        }
//         incrementing both behind and ahead if ahead->next is not null
        while(ahead->next != nullptr){
            ahead = ahead->next;
            behind = behind->next;
        }
//         deleting the node
        behind->next = behind->next->next;
//         return node->next
        return node->next;
    }
};
// @lc code=end

