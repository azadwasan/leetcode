//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#pragma once
#include <vector>

class TwoSumII {
public:

//Because the array is already sorted, we can use this to our advantage.
//Define two pointers that points the first and the last element.
//If the sum of numbers at two pointers
// a. is equal to to the target, return the result
// b. less than the target, increment the left pointer so that the sum can increase
// c. greater than the target, decrement the right pointer so that the sum can decrease
//Exit the loop if left is greater than the right, as we have searched the whole array and sum doesn't exists.
	std::vector<int> twoSumPointers(std::vector<int> nums, int target) {
		int l = 0, r = std::size(nums) - 1;
		while (l < r) {
			int sum = nums[l] + nums[r];
			if (sum < target) {
				l++;
			}
			else if (sum > target) {
				r--;
			}
			else {
				return {l + 1, r + 1};
			}
		}
		return {};
	}


// Binary Search based solution
	std::vector<int> twoSumBinarySearch(std::vector<int> nums, int target) {
		for (int i = 0; i < std::size(nums)-1; i++) {
			std::cout << "Checking for the number " << i << std::endl;
			int second = target - nums[i];
			int pos = binary_search(nums, second, i + 1, std::size(nums)-1);
			if (pos != -1) {
				return { i+1, pos+1 };
			}
		}
		return {};
	}

	int binary_search(std::vector<int>& nums, int target, int left, int right) {
		while (left <= right) {
			int m = floor((left + right) / 2);
			if (nums[m] < target) {
				left = m + 1;
			}
			else if (nums[m] > target) {
				right = m - 1;
			}
			else {
				return m;
			}
		}
		return -1;
	}
};