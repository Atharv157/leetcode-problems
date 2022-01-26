/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         tackling with edge test cases
        if(!list1 && !list2) return nullptr;
        if(!list1) return list2;
        if(!list2) return list1;
        
//         creating a dummy node and linking it to the list1 
//         our list1 is for insertions and list2 is for iterating
        ListNode *dummy = new ListNode;
        dummy->next = list1;
        
        ListNode *prev = dummy;
        ListNode *curr = list1;
        ListNode *cache;
//         moving temp ptr through the list2
        ListNode *temp = list2;
        
        while(curr && temp){
            if(temp->val <= curr->val)
            {
//                 we have to insert temp into this list if temp val <= curr val else just increment prev and curr
                prev->next = temp;
                cache = temp->next;
                temp->next  = curr;
                temp = cache;
                prev = prev->next;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }
//         if any nodes are remaining in list2, then adding them to the list1
//         also if flow enters this while loop this means that sitll elements are remaining in list2 
//         but list1 is exhausted hence we know that prev is at tail and curr is null
//         therefore treating prev as tail below
        while(temp){
            cache = temp->next;
            temp->next = nullptr;
            prev->next = temp;
            prev = prev->next;
            temp = cache;
        }
        
        return dummy->next;
    }
};
// @lc code=end

