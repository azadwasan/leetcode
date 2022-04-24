#pragma once
//https://leetcode.com/problems/top-k-frequent-elements/
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

class TopKFrequentElements {
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
		std::unordered_map<int, int> map{};
		for (int num : nums) {
			if (!map[num]) {
				map[num] = 1;
			}
			else {
				map[num]++;
			}
		}


		class PairCompare{
		public:
			bool operator()(const std::pair<int, int>& left, const std::pair<int, int>& right) { return left.second < right.second; }
		};
		//auto cmp = [](const std::pair<int, int>& left, const std::pair<int, int>& right) {return left.second < right.second; };
		//std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> queue{ map.begin(), map.end(), cmp };
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairCompare> queue{ map.begin(), map.end(), PairCompare{} };

		std::vector<int> topK{};
		while (topK.size() < k && !queue.empty()) {
			topK.emplace_back(std::move(queue.top().first));
			queue.pop();
		}

		return topK;
	}

	void printMap(std::unordered_map<int, int> map) {
		for (auto iter = map.begin(); iter != map.end(); iter++) {
			std::cout << (iter->first) << " -> " << (iter->second) << std::endl;
		}
	}
	
};