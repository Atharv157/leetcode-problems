/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if(!head->next) return head;
        
        int count = 0;
        ListNode *tail = head;
        ListNode *curr = head;
        ListNode *headcache = head;
        // getting count of nodes
        while(curr){
            count++;
            tail = curr;
            curr = curr->next;
        }
        
        if(k%count==0) return head;
        else{
            int counter = 1;
            int diff = count - k%count;
            curr = head;
            while(counter!=diff){
                curr = curr->next;
                counter++;
            }
            headcache = curr->next;
            curr->next = nullptr;
            tail->next = head;


        }
        return headcache;
    }
};
// @lc code=end

