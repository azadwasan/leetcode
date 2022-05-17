//https://leetcode.com/problems/median-of-two-sorted-arrays/
#pragma once
#include <vector>
#include <set>
#include <iostream>>

//We can follow various approaches to solve this problem.
//1. Simply merge the two array and sort them once, but that would have a complexity of nlog(n) due to sorting
//2. Maintain two heaps (priority queue), one max heap and a min heap. However, the complexity again would be n(log n), 
// because we would be inserting n items and each item costs log n. 
// More here: https://stackoverflow.com/questions/44650882/time-complexity-of-a-priority-queue-in-c
//3. Third apporach would be to maintain a sorted hash set, which has a complexity of log(n) for insertion of n elements.
//Which is pretty much the solution that the question is asking for. For complexity details plz check further:
// https://en.cppreference.com/w/cpp/container/set
// https://stackoverflow.com/questions/12776485/complexity-of-setinsert

class TwoSortedArrayMedian {
public:
	double findMedianSortedArray(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::multiset<int> merged_set{ nums1.begin(), nums1.end() };
		for (auto& ele : nums2) {
			merged_set.emplace(ele);
		}

		for (auto& sEle : merged_set) {
			std::cout << sEle << std::endl;
		}
		double result = 0;
		if (merged_set.size() == 0) {
			result = 0;;
		}
		else if (merged_set.size() == 1) {
			result = *(merged_set.begin());
		}
		else {
			auto iter = merged_set.begin();
			for (int counter = 1; iter != merged_set.end() && counter < merged_set.size() / 2; iter++, counter++) {
			}

			if (merged_set.size() % 2) {
				result = *(++iter);
			}
			else {
//				std::cout << "Two middle values = (" << (*iter) << ", " << (*(++iter)) << std::endl;

				result = (*iter + *(++iter))/2.0;
			}

		}
		return result;
	}
};