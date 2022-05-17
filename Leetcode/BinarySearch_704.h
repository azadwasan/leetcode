//https://leetcode.com/problems/binary-search/submissions/
#pragma once
#include <vector>

class BinarySearch {
public:
	int search(std::vector<int>& nums, int target) {
		int l = 0, r = std::size(nums)-1;
		while (l <= r) {
			int m = floor((l + r) / 2.0);
			if (target < nums[m]) {
				r = m - 1;
			}
			else if (target > nums[m]) {
				l = m + 1;
			}
			else {
				return m;
			}
		}
		return -1;
	}
};