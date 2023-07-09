//
// 剑指 Offer 18. 删除链表的节点
//

#pragma once

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (!head) {
            return head;
        }

        if (head->val == val) {
            return head->next;
        }

        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                return head;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};