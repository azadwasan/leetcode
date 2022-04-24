#pragma once
#include <vector>
#include <numeric>
#include <iostream>

class DuplicateNumber {
public:
	int findDuplicateNumber(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < std::size(nums)-1; i++) {
			if (nums[i] == nums[i + 1]) {
				return nums[i];
			}
		}
	}

	//This is Floyd's algorithm to detect loops in a Linked List.
	//The operations is very simple. It treats the values as indices to find the next value, which makes it jump from one value to the other, hence eventually get itself trapped into a loop.
	//1. It start with two pointers 1. Slow (which increments by one index value) 2. Fast (which increments by two indices), so it jumps twice
	//2. Keep looping until fast and slow are equal.
	//3. Now increment fast only by one and move slow to the origin (0).
	//4. Loop until both fast and slow are equal. This is the point of the loop.
	//HENCE, the duplicate numbers in this case.

	int findDuplicate_fastSlow(std::vector<int> nums) {
		int slow = 0;
		int fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);

		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}

		return slow;
	}
};