//
// 剑指 Offer 52. 两个链表的第一个公共节点
//

#pragma once

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @brief 你变成我，走过我走过的路。我变成你，走过你走过的路。然后我们便相遇了...
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
