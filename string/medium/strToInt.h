//
// 剑指 Offer 67. 把字符串转换成整数
//

#pragma once

#include <string>
#include <limits>

class Solution {
public:
    int strToInt(std::string str) {
        if (str.empty()) {
            return 0;
        }

        using retType = decltype(std::declval<Solution>().strToInt(std::declval<std::string>()));
        constexpr auto max = std::numeric_limits<retType>::max();
        constexpr auto min = std::numeric_limits<retType>::min();

        retType result = 0;
        uint32_t idx = 0;
        while (idx < str.size() && str[idx] == ' ') {
            ++idx;
        }
        int8_t sign = 1;
        if (idx < str.size() && (str[idx] == '+' || str[idx] == '-')) {
            sign = str[idx++] == '+' ? 1 : -1;
        }

        for (; idx < str.size() && std::isdigit(str[idx]); ++idx) {
            const char c = str[idx];
            const uint8_t num = c - '0';
            if (sign == 1 && result > (max - num) / 10) {
                return max;
            }
            if (sign == -1 && result < (min + num) / 10) {
                return min;
            }
            result = result * 10 + sign * num;
        }
        return result;
    }

};
