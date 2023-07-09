//
// 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
//

#pragma once

#include <vector>
#include <cstdint>

class Solution {
public:
    std::vector<int> exchange(std::vector<int> &nums) {
        if (nums.empty()) {
            return nums;
        }

        uint32_t left = 0;
        uint32_t right = nums.size() - 1;
        while (left < right) {
            while (nums[left] % 2 != 0) {
                if (left == right) {
                    return nums;
                }
                ++left;
            }
            while (nums[right] % 2 == 0) {
                if (left == right) {
                    return nums;
                }
                --right;
            }
            std::swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};
