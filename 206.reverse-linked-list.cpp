/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode *orighead = head;
        ListNode *newhead = head;
        ListNode *temp = head;
        while(orighead->next){
            temp = orighead->next;
            orighead->next = temp->next;
            temp->next = newhead;
            newhead = temp;
        }
        return newhead;
    }
};
// @lc code=end

