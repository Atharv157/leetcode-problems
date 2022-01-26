/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tempA = l1;
        ListNode *tempB = l2;
        ListNode *head = new ListNode();
        ListNode *temp = head;
        
        ListNode *prev = head;
        int sum = 0;
        int carry = 0;
// this loop will only end when both the lists are exhausted
        while(tempA || tempB)
        {
            if(tempA && tempB) sum = tempA->val + tempB->val + carry;
            else if(tempA && !tempB) sum = tempA->val + carry;
            else if(!tempA && tempB) sum = tempB->val +carry;
            
            if(sum>9)
            {
                sum = sum - 10;
                carry = 1;
            }
            else carry = 0;
            temp->val = sum;
            ListNode *nxt = new ListNode();
            temp->next = nxt;
            prev = temp;
            temp = temp->next; 
            
            if(tempA)tempA = tempA->next;
            if(tempB)tempB = tempB->next;
            
        }
        
        if(carry){
            temp->val = 1;
        }
        else prev->next = nullptr;

        
        return head;
        }
};
// @lc code=end

