/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    // better logic
public:
     ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;
        
        while(odd->next && even->next){
            odd->next = even->next; //Connect all odds
            even->next = odd->next->next;  //Connect all evens
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start;   //Place the first even node after the last odd node.
        return head; 
    }


    // my own previous logic
// public:
//     ListNode* oddEvenList(ListNode* head) {
        
//         if(head == nullptr) return head;
        
        
//         ListNode *oddend = head;
//         ListNode *prev = head;
//         ListNode *curr  = prev->next;
        
//         if(curr == nullptr) return head;
        
//         int count = 2;
//         while(curr){
//             if(count%2 == 1)
//             {
// //                 odd node
//                 prev->next = curr->next;
//                 curr->next = oddend->next;
//                 oddend->next = curr;
//                 oddend = oddend->next;
//                 curr = prev->next;
//             }
//             else
//             {
// //             even node
//                 prev = prev->next;
//                 curr = curr->next;
//             }
//             count++;
//         }
        
//         return head;
//     }
};
// @lc code=end

