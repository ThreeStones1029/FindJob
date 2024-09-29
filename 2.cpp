#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 跳过重复元素
        int target = -nums[i];
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) ++left; // 跳过重复元素
                while (left < right && nums[right] == nums[right - 1]) --right; // 跳过重复元素
                ++left; --right;
            } else if (nums[left] + nums[right] < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return result;
}