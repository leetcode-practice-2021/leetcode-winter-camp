/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
        if(head == nullptr || head->next==nullptr){
            return head;
        }
        // ListNode* dummy = new ListNode(-1, head);
        // ListNode* pre = head;
        // ListNode* cur;
        // while(pre->next != nullptr){
        //     cur = pre->next;
        //     pre->next = cur->next;
        //     cur->next = dummy->next;
        //     dummy->next = cur;
        // }
        // return dummy->next;
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};
// @lc code=end

