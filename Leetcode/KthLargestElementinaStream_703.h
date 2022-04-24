#pragma once
//https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include <queue>
#include <vector>
#include <functional>

//Solution: We can have n number and we only need kth largest element. So, we can use a minHeap. 
// Remove n-k element, as we don't need them and we immediately have kth element as the top element.
//Complexity: Creating head = O(n)
//kth element access is O(1) (because of the above design)
//Removing elements = log(n) and removing n-k smaller elements = n log(n) (k could be really small).
//Adding is log(n) and if we have m elements add = O(m log(n))
//So, if we look at all the time complexities, the worst case turns out to be O(n log(n)) (Removing the k elements initially).

class KthLargest {
public:
	KthLargest(int k, std::vector<int>& nums):k(k), queue(nums.begin(), nums.end()) {
		while (queue.size() > k) {
			queue.pop();
		}
	}
	int add(int num) {
		queue.push(num);
		if (queue.size() > k) {
			queue.pop();
		}
		return queue.top();
	}

	void displayQueue(std::priority_queue<int, std::vector<int>, std::greater<int>> queue) {
		while (!queue.empty()) {
			std::cout << queue.top()<<std::endl; queue.pop();
		}
	}
private:
	std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
	int k;
};