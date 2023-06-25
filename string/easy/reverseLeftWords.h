//
// 剑指 Offer 58 - II. 左旋转字符串
//

#pragma once

#include <string>

class Solution {
public:
    std::string reverseLeftWords(std::string s, int n) {
        const auto len = s.size();
        std::string r = s;
        for (int i = 0; i < len; ++i) {
            r[i < n ? i + len - n : i - n] = s[i];
        }
        return r;
    }
};

class Solution1 {
public:
    std::string reverseLeftWords(std::string s, int n) {
        return s.substr(n) + s.substr(0, n);
    }
};
