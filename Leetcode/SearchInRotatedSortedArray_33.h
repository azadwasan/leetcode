//https://leetcode.com/problems/search-in-rotated-sorted-array/
#pragma once
#include <vector>

//Solution video: https://www.youtube.com/watch?v=U8XENwh8Oy8
//The solution is based on the idea that we break the array into two halfs. 1. Left sorted portion 2. Right sorted portion.
//First of all we have to determine in which portion are we, which is relatively simple. 
//We check if left most value Array[left] (initially 0 index value), if it is less than the middle value Array[m] then we are in the left sorted portion.
//The reason that we are in the left part portion is that due to rotation the larger numbers have moved to the left and
//if we are in the right sorted portion, these numbers will be smaller than the left sorted portion.
// E.g. [5 6 7   1 2 3 4] if we land on the right side, A[l]<A[m] will not be true.
//So, now we have the portion figured out. Now, we need to adjust left and right.
// Lets say we are in the left part:
//		If target is larger than Array[m] then we just set left = m +1
//		If target is less than the left most, T<Array[l] then we have to check to the right due to rotation -> left = m + 1
//		Otherwise, it is between Array[l] and Array[m] somewhere, i.e., right = m-1
// Similarly, if we are on the right side:
//		If T<Array[m], then we move right = m-1 (it is to the left of 'm' somewhere)
//		If T>Array[r], right = m - 1; (due to rotation, it is to the left of 'm' some where)
//		Otherwise, it is to the right somewhere. left = m + 1

//The following idea is interesting but it has a drawback that it parses the whole array anyway to find the rotation.
//This could be a useful solution in the case we only figureout the rotation once and then we perform searches multiple times.

class RotatedSortedArraySearch {
public:
	int search(std::vector<int>& nums, int target) {
		int l = 0, r = std::size(nums) - 1;
		while (l <= r) {
			int m = floor((l + r) / 2.0);
			if (nums[m] == target) {
				return m;
			}
			if (nums[l] <= nums[m]) {
				if (target > nums[m] || target < nums[l]) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			else {
				if (target < nums[m] || target > nums[r]) {
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
		}
		return -1;
	}
};

class RotatedSortedArraySearchMappedIndex {
public:
	int search(std::vector<int>& nums, int target) {
		int l = 0, r = std::size(nums)-1;
		int rotation = findRotation(nums);

		while (l <= r) {
			int m = floor((l + r) / 2.0);
			int mappedIndex = mapIndex(m, rotation, std::size(nums));
			int mValue = nums[mappedIndex];
			if (target < mValue) {
				r = m - 1;
			}
			else if (target > mValue){
				l = m + 1;
			}
			else {
				return mappedIndex;
			}
		}
		return -1;
	}

private:
	int findRotation(const std::vector<int>& nums) {
		for (int i = 1; i < std::size(nums); i++) {
			if (nums[i] - nums[i - 1] < 0) {
				return i;
			}
		}
		return 0;
	}

	int mapIndex(int index, int rotation, int length) {
		index += rotation;
		if (index >= length) { index -= length; }
		return index;
	}
};