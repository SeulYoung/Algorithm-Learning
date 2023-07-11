//
// 剑指 Offer 58 - I. 翻转单词顺序
//

#pragma once

#include <string>
#include <deque>

class Solution {
public:
    std::string reverseWords(std::string s) {
        if (s.empty()) {
            return s;
        }

        uint32_t left = 0;
        uint32_t right = s.size() - 1;
        while (left <= right && s[left] == ' ') {
            ++left;
        }
        while (left <= right && s[right] == ' ') {
            --right;
        }

        std::deque<std::string> deque;
        while (left <= right) {
            uint32_t end = left;
            while (end <= right && s[end] != ' ') {
                ++end;
            }
            if (end != left) {
                deque.push_back(s.substr(left, end - left));
            }
            left = end + 1;
        }

        std::string result{};
        while (!deque.empty()) {
            result += deque.back();
            deque.pop_back();
            if (!deque.empty()) {
                result += ' ';
            }
        }
        return result;
    }
};


class Solution1 {
public:
    std::string reverseWords(std::string s) {
        if (s.empty()) {
            return s;
        }
        std::reverse(s.begin(), s.end());
        uint32_t idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }

            s[idx++] = s[i];
            int end = i + 1;
            while (end < s.size() && s[end] != ' ') {
                s[idx++] = s[end++];
            }
            std::reverse(s.begin() + idx - (end - i), s.begin() + idx);
            if (idx < s.size()) {
                s[idx++] = ' ';
            }
            i = end;
        }
        if (idx > 0 && s[idx - 1] == ' ') {
            --idx;
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};
