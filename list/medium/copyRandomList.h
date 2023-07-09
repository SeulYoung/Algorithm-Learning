//
// 剑指 Offer 35. 复杂链表的复制
//

#pragma once

#include <vector>
#include <unordered_map>
#include <cstdint>

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        Node *cur = head;
        while (cur) {
            Node *new_node = clone(cur);
            new_node->next = cur->next;
            cur->next = new_node;
            cur = new_node->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        Node *new_head = head->next;
        cur = head;
        while (cur) {
            Node *next = cur->next;
            cur->next = cur->next->next;
            if (next->next) {
                next->next = next->next->next;
            }
            cur = cur->next;
        }
        return new_head;
    }

private:
    static Node *clone(Node *node) {
        Node *new_node = new Node{node->val};
        return new_node;
    }
};

class Solution1 {
public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        Node *new_head = clone(head);
        new_head->next = clone(head->next);
        new_head->random = clone(head->random);

        Node *cur = new_head->next;
        head = head->next;
        while (head) {
            cur->next = clone(head->next);
            cur->random = clone(head->random);
            cur = cur->next;
            head = head->next;
        }
        return new_head;
    }

private:
    Node *clone(Node *node) {
        if (!node) {
            return nullptr;
        }
        if (map_.contains(node)) {
            return map_[node];
        }
        Node *new_node = new Node{node->val};
        map_.emplace(node, new_node);
        return new_node;
    }

    std::unordered_map<Node *, Node *> map_;
};