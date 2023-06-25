//
// Created by 94817 on 2023/6/24.
//

#pragma once

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        return dfs(nullptr, head);
    }

private:
    ListNode *dfs(ListNode *pre, ListNode *cur) {
        if (!cur) {
            return pre;
        }
        ListNode *head = dfs(cur, cur->next);
        cur->next = pre;
        return head;
    }
};

class Solution1 {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
