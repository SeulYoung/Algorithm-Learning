//
// 剑指 Offer 22. 链表中倒数第k个节点
//

#pragma once

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        if (!head) {
            return head;
        }

        ListNode *fast = head;
        ListNode *slow = head;
        while (k--) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
