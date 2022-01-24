/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
//         creating dummy node
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        ListNode *prev = dummy;
        ListNode *curr = head;
        ListNode *del;   
//         iterating until curr is null
        while(curr){
//             if value matches then set prev->next = cur->next
            if(curr->val == val)
            {   
                del = curr;
                prev->next = curr->next;
                curr = curr->next;
                // delete(del);
            }
//             if it doesnt then just increment both
            else{
                prev = prev->next;
                curr = curr->next;
            }
            
        }
            
        return dummy->next;
    }
};
// @lc code=end

