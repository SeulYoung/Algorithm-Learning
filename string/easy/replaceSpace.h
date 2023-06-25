//
// 剑指 Offer 05. 替换空格
//

#pragma once

#include <string>

class Solution {
public:
    std::string replaceSpace(std::string s) {
        if (s.empty()) {
            return "";
        }

        int count = 0;
        for (const auto c: s) {
            if (c == ' ') {
                ++count;
            }
        }
        auto i = s.size() - 1;
        auto j = s.size() + 2 * count - 1;
        s.resize(s.size() + 2 * count);


        while (i != j) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
                --i;
                continue;
            }
            s[j--] = s[i--];
        }
        return s;
    }
};

class Solution1 {
public:
    std::string replaceSpace(std::string s) {
        if (s.empty()) {
            return "";
        }

        const auto size = s.size();
        std::string result{};

        int last_pos = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] == ' ') {
                result += s.substr(last_pos, i - last_pos);
                result += "%20";
                last_pos = i + 1;
            }
        }
        if (s[size - 1] != ' ') {
            result += s.substr(last_pos, size - last_pos);
        }

        return result;
    }
};
