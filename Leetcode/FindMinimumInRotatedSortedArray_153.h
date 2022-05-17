//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#pragma once
#include <vector>

//Solution video: https://www.youtube.com/watch?v=nIVW4P8b1VA
//The basic idea follows the same fundamental algorithm that we first need to figure out in which portion of the array are we currently.
//We run the standard binary search as usual.
//The first condition is the most basic condition that checks if left most value is smaller than right most then we already are in the lowest to highest sorted portion of the array.
//Hence, we can simply take the left most value and it could possibily the globally smallest value.
//We do need to record the last smallest value to keep track of the smallest value. 
//Next, we need to see if the middle value is greater than left most, then we are in the left sorted portion of the array.
//This means we are in the part where we have larger values. So, we need to search to the right.
//That is all the logic. The only key here to remember is that we need to keep track of the min value.

class FindMinInRotatedSortedArray {
public:
	int search(std::vector<int>& nums) {
		int l = 0, r = std::size(nums) - 1;
		int res = nums[0];

		while (l <= r) {
			if (nums[l] < nums[r]) {	//We have a completely sorted array, so just take the smallest
				res = min (res, nums[l]);	
				break;
			}

			int m = floor((l + r) / 2.0);
			res = min(res, nums[m]);

			if (nums[m] >= nums[l]) { //We are in the left portion of the sorted array
				l = m + 1;
			}
			else {
				r = m -1;
			}
		}
		return res;
	}
};

//There is an other very interesting solution, but I couldn't understand exactly all the edge cases and how the subscripts were being set
//However, it has the advantage that it doesn't need to store the intermediate results
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/48493/Compact-and-clean-C%2B%2B-solution