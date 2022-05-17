#pragma once
#include <vector>
#include <unordered_map>

class TwoSum {
public:
	std::vector<int> FindTwoSum(const std::vector<int>& nums, int target) {
		std::unordered_map<int, int> map{};
		for (int i = 0; i < std::size(nums); i++) {
			map[nums[i]] = i;
		}
		for (int i = 0; i < std::size(nums); i++) {
			auto iter = map.find(target - nums[i]);
			if (iter != map.end() && iter->second!=i) {
				return { i, iter->second };
			}
		}
	}
};