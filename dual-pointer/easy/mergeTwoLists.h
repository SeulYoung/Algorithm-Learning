//
// 剑指 Offer 25. 合并两个排序的链表
//

#pragma once

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy{0};
        ListNode *cur = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                appendNode(cur, l2);
            } else {
                appendNode(cur, l1);
            }
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }

private:
    static void appendNode(ListNode *&cur, ListNode *&next) {
        cur->next = next;
        cur = cur->next;
        next = next->next;
    }
};
