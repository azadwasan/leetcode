//https://leetcode.com/problems/k-closest-points-to-origin/
#pragma once
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

//Complexity analysis: Adding O(n). retrieve an element log(n) and retrieving k elements k log(n), worst case n log(n).
//Our solution is actully good enough. 
//Alternate solutions would be 
//1. Sort the vectoring using any sorting algorithm.
//2. Use a maxHeap instead of minHeap and add only K element first. 
//	If the new element is larger than the max element, we can skip it, otherwise we can add the new element and remove the largest.

//Check below for a very nice concise solution (the logic is same, but the way the code is wriiten is really concise)
class Compare {
public:
	bool operator()(const std::vector<int>& left, const std::vector<int>& right) const {
		return (left[0] * left[0] + left[1] * left[1]) > (right[0] * right[0] + right[1] * right[1]);
	}
};

class KClosestPointsToOrigin {
public:
	std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k){
		for (auto point : points) {
			queue.push(point);
		}
		std::vector<std::vector<int>> result;
		int count = 0;
		while (count < k && !queue.empty()) {
			result.push_back(queue.top());
			queue.pop();
			count++;
		}
		return result;
	}

	void displayQueue(std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Compare> q) {
		while(!q.empty()) {
			auto val = q.top();
			q.pop();
			std::cout << "(x, y) = (" << val[0] << ", " << val[1] << ")" << std::endl;
		}
	}

	void displayVector(const std::vector<std::vector<int>>& result) const {
		for (auto val : result) {
			std::cout << "(x, y) = (" << val[0] << ", " << val[1] << ")" << std::endl;
		}
	}

//	std::function<bool(const std::vector<int>&, const std::vector<int>&)> cmp = [](std::vector<int> left, std::vector<int> right) {return false; };
	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Compare>  queue{};
};

/*
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& P, int k) {
		auto euclidean = [](auto& p) { return p[0] * p[0] + p[1] * p[1]; };
		auto comp = [&](auto& a, auto& b) { return euclidean(a) > euclidean(b); };
		make_heap(begin(P), end(P), comp);

		for (int i = 0; i < k; i++)
			pop_heap(begin(P), end(P) - i, comp);

		return vector<vector<int>>(begin(P) + size(P) - k, end(P));
	}
};*/