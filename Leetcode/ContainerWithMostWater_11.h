//https://leetcode.com/problems/container-with-most-water/

#pragma once
#include <vector>
#include <algorithm>

class MaxWaterContainer{ 
public:

	int maxAreaBruteForce(std::vector<int>& height) {
		int maxArea = 0;
		for (int left = 0; left < std::size(height); left++) {
			for (int right = std::size(height)-1; right > left; right--) {
				int area = std::min(height[left], height[right]) * (right - left);
				maxArea = std::max(area, maxArea);
			}
		}
		return maxArea;
	}

	//The basic idea is really simple. The brute force above solves the problem really easily but is expensive (O(N^2)).
	//Following is a two pointer approach. The key point to note is that height essentially defines how much water will be trapped.
	//So, we have left and right pointers. The increment/decrement of the left and right respective depends of which one of the two heights is smaller.
	//The smaller height pointer will be changed (left->increment, right->decrement)

	int maxAreaPointers(std::vector<int>& height) {
		int maxArea = 0;
		int left = 0;
		int right = std::size(height) - 1;
		while (left < right) {
			maxArea = std::max(std::min(height[left], height[right]) * (right - left), maxArea);
			if (height[left] < height[right]) {
				left++;
			}
			else {
				right--;
			}
		}
		return maxArea;
	}
};
