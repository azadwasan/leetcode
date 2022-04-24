//https://leetcode.com/problems/longest-consecutive-sequence/

#pragma once
#include <vector>
#include <unordered_set>
#include <algorithm>


//https://leetcode.com/problems/longest-consecutive-sequence/discuss/41060/A-simple-C%2B%2Bsolution-using-unordered_set.And-simple-consideration-about-this-problem
//The above is an excellent solution, because unordered set is O(n) at at the most in insertion. 
//The search is O(1). Hence, it is one of the best solutions.
//This solution has some unnecessary operations that are not needed.
//The simpler solution is the one suggested in the neetcode video. 
// 1. For each number, check if a previous neighbor number exists.
//    a. If yes, then it is not the start of the sequence
//    b. Otherwise, it is the start of a new sequence.
// 2. Now, simply start looking for the next numbers in this sequence (a while loop) until we can't find next numbers
//    a. Keep counting how far have we come
//	  b. at the end of the sequence, reassign the maxValue to the max of the previous and th new length

class LongestConsectiveSequence{
public:


	int longestConsectiveUnordered(std::vector<int>& nums) {
		std::unordered_set<int> set{nums.begin(), nums.end()};
		int maxValue = 0;
		for (auto num : nums) {
			if (set.find(num - 1) == set.end()) {
				int length = 1;
				while (set.find(num + length++) != set.end()) {}
				maxValue = max(maxValue, length-1);
			}
		}
		return maxValue;
	}

	int longestConsecutive(std::vector<int> &num) {
		std::unordered_set<int> record(num.begin(), num.end());
		int res = 1;
		for (int n : num) {
			if (record.find(n) == record.end()) continue;
			record.erase(n);
			int prev = n - 1, next = n + 1;
			while (record.find(prev) != record.end()) record.erase(prev--);
			while (record.find(next) != record.end()) record.erase(next++);
			res = max(res, next - prev - 1);
		}
		return res;
	}
};