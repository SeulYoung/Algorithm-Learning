//
// 剑指 Offer 06. 从尾到头打印链表
//

#pragma once

#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    std::vector<int> reversePrint(ListNode *head) {
        result_.clear();
        dfs(head);
        return result_;
    }

private:
    void dfs(ListNode *node) {
        if (!node) {
            return;
        }
        dfs(node->next);
        result_.push_back(node->val);
    }

    std::vector<int> result_;
};

class Solution1 {
public:
    std::vector<int> reversePrint(ListNode *head) {
        std::vector<int> result;
        while (head) {
            result.insert(result.begin(), head->val);
            head = head->next;
        }
        return result;
    }
};
