/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;
        
        if(head==nullptr)
            return nullptr;
//         find the convergence point of slow and fast ptr
        while(slow != nullptr && fast != nullptr && slow->next != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
//             if convergence found then iterate both slow and entry till they match
//             their matching point is the start of the cycle
            if(slow == fast)
            {
                while(slow != entry)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                if(slow == entry)
                {
                    return slow;
                }
                    
            }
        }
        
        return nullptr;
    }
};
// @lc code=end

