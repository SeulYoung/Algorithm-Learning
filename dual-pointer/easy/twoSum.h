//
// 剑指 Offer 57. 和为s的两个数字
//

#pragma once

#include <vector>
#include <cstdint>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        uint32_t left = 0;
        uint32_t right = nums.size() - 1;
        while (left < right) {
            auto sum = nums[left] + nums[right];
            if (sum > target) {
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                return {nums[left], nums[right]};
            }
        }
        return {nums[left], nums[right]};
    }
};
