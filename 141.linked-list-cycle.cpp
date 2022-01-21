/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if(head == nullptr)
            return false;
        while(true){
            slow = slow->next;
            if(fast->next == nullptr)
                break;
            fast = fast->next->next;
            if(slow != nullptr && fast != nullptr){
                if(&slow->val == &fast->val)
                    return true;
            }
            else break;
            
        }
        return false;
    }
};
// @lc code=end

