/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *up = headA;
        ListNode *down = headB;
        int upcount = 0 , downcount = 0;
        int flag = 0;
        while(true)
        {
            if(up->next == nullptr && down->next == nullptr && up != down)
                return nullptr;
//             common point achieved hence breaking the loop
            if(up == down)
                break;
            
            else if(up->next != nullptr && down->next != nullptr)
            {
//                 both LL are remaining 
                up = up->next;
                down = down->next;
                upcount++;
                downcount++;
            }
            
            else if(up->next != nullptr && down->next == nullptr)
            {
                up = up->next;
                upcount++;
            }
            
            else if(up->next == nullptr && down->next != nullptr)
            {
                down = down->next;
                downcount++;
            }
            
            
        }
        
        
        int diff = abs(upcount - downcount);
        if(diff == 0)
            return up;
        else if(upcount>downcount){
            up = headA;
            down = headB;
//             upper list has extra nodes
            while(diff!=0){
                up = up->next;
                diff--;
            }
        }
        else{
//             down list has extra nodes
            up = headA;
            down = headB;
             while(diff!=0){
                down = down->next;
                diff--;
            }
        }
        while(up != down){
            up = up->next;
            down = down->next;
        }
        return down;
            
    }
};
// @lc code=end

