/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
// created a function to reverse linked list
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *prev = head;
        ListNode *curr = prev->next;
        while(curr){
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            curr = prev->next;
        }
        return head;
    }


    bool isPalindrome(ListNode* head) {
        // for tackling edge test cases
        if(!head->next) return head;
        
        if(!head->next->next){
            if(head->val != head->next->val) return false;
            else return true;
        }
        // code to find the mid of the linked list
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
//         now the slow ptr is at mid of the linked list,
//  now we have to reverse the second half of linked list
        ListNode *headB = reverseList(slow->next);
//         second half is now reversed, so we have to just check for matching values
        while(headB){
            if(head->val != headB->val) return false;
            head = head->next;
            headB = headB->next;
        }
        
            
        return true;
    }
};
// @lc code=end

