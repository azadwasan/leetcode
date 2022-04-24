//215. Kth Largest Element in an Array

#pragma once
#include <algorithm>
#include <queue>
#include<vector>

class KthLargestElement {
public:
	int findKethLargestSorting(std::vector<int>& nums, int k) {
		std::sort(nums.begin(), nums.end(), [](int left, int right) {return left < right; });
		displayVector(nums);
		std::cout << "Kth largest = " << nums[nums.size() - k];
		return 0;
	}

	//1. Construct a min-heap. 2. Only add k elements first. 
	int findKthLargestHeap(const std::vector<int>& nums, int k) const {
		std::priority_queue<int, std::vector<int>, std::greater<int>> maxQueue;
		for (auto num : nums) {
			if (maxQueue.size() < k) {
				maxQueue.push(num);
			}
			else {
				if (num > maxQueue.top()) {
					maxQueue.pop();
					maxQueue.push(num);
				}
			}
		}
		displayHeap(maxQueue);
		std::cout << "Kth Max values = " << maxQueue.top() << std::endl;
		return maxQueue.top();
	}

	template<class T>
	void displayVector(T container) {
		for (auto val : container) {
			std::cout << val << std::endl;
		}
	}

	void displayHeap(std::priority_queue<int, std::vector<int>, std::greater<int>> heap) const {
		while (!heap.empty()) {
			std::cout << heap.top() << std::endl;
			heap.pop();
		}
	}
};