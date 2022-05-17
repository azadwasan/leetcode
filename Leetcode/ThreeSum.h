//https://leetcode.com/problems/3sum/

#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>

class ThreeSum {
public:

//Though the basic problem is not too difficult to solve. But, the condition of not including the duplicate entries, makes it pretty hard.
//The basic idea is simple: Loop over all numbers and sum the number + twoSum of the remaining numbers (Two Sum II, pointer based solution)
//The trick to avoid the duplicates is as follows:
//  1. Sort the array
//	2. Loop over all the numbers and store it as 'n' 
//  3. Perform a two sum of the all the numbers to the right of 'n' (define l and r)
//  4. The only addition is when we are recording the vector, we have to skip over all the numbers that are the same from the left side, so that there are no duplicates for the second position.
//  5. Now to get rid of duplicates for the first position, skip all the numbers that are same as the last one.
// We don't need to do it for the third number ('r'), because we know that this picece of code finds the sum of two numbers and the target is predefined.
// As soon as we change the left number, the right number will no longer be the one that will add up to the previous target (the sum will be higher).
// Hence, the first if conditions will cause 'r' to decrement anyway. However, it is a slight bit of optimization to to also decrement 'r' like 'l' because the outer loop will calculate sum and make comparisons etc. Hence, a dumb loop will be better.
	std::vector<std::vector<int>> findThreeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> result;
		const int TARGET = 0;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < std::size(nums);) {
			int n = nums[i];
			int l = i + 1, r = std::size(nums) - 1;
			while (l < r) {
				int sum = n + nums[l] + nums[r];
				if (sum > TARGET) {
					r--;
				}
				else if (sum < TARGET) {
					l++;
				}
				else {
					result.push_back({ n, nums[l], nums[r] });
					l++;
					while (nums[l - 1] == nums[l] && l < r) l++;
				}
			}
			i++;
			while (i<std::size(nums) && nums[i - 1] == nums[i]) i++;
		}
		return result;
	}


	//The brute force approach doesn't work, as it adds duplicate entries
	std::vector<std::vector<int>> findThreeSumsBruteForce(const std::vector<int>& nums) {
		std::vector<std::vector<int>> result;
		std::unordered_map<int, int> map;
		for (int i = 0; i < std::size(nums); i++) {
			map[nums[i]] = i;
		}
		for (int i = 0; i < std::size(nums); i++) {
			for (int j = i+1; j < std::size(nums); j++) {
				auto iter = map.find(-1* (nums[i]+nums[j]));
				if (iter != map.end() && iter->second!=i && iter->second!=j) {
					result.push_back({ i, j, iter->second });
				}
			}
		}
		return result;
	}
};