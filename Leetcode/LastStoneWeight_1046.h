#pragma once
//https://leetcode.com/problems/last-stone-weight/
#include <iostream>
#include <vector>
#include <queue>

//NOTE: Do check Neetcode solution below, as it is a lot more concise and easy to understand.

//Submission Results
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
//Memory Usage : 7.8 MB, less than 33.22% of C++ online submissions for Last Stone Weight.

//Complexity. 
//		Insertion of the whole array = O(n)
//		Removing the largst element = log(n) 
//		Removing n number of elements = n log(n) -> This is the overall complexity.

class SlashingStones{
	public:
		int lastStoneWeight(std::vector<int>& stones) {
			std::priority_queue<int, std::vector<int>> hStones(stones.begin(), stones.end());
			int x = 0, y = 0;
			while (!hStones.empty()) {
				try {
					y = getElement(hStones);
					x = getElement(hStones);
				}
				catch (int e) {
					break;
				}
				if (x != y) {
					hStones.push(y - x);
				}
				else {
					x = y = 0;
				}
			}
			return y;
		}
		int getElement(std::priority_queue<int, std::vector<int>>& queue) {
			int top = 0;
			if (!queue.empty()) {
				top = queue.top();
				queue.pop();
			}
			else {
				throw 1;
			}
			return top;
		}
		void displayQueue(std::priority_queue<int, std::vector<int>> prioQueue) {
			while (!prioQueue.empty()) {
				std::cout << prioQueue.top() << std::endl;
				prioQueue.pop();
			}
		}
};

//Neetcode solution. It is a lot better than our solution, as it is really simple and a lot less code.
/*
class SlashingStones {
public:
	int lastStoneWeight(std::vector<int>& stones) {
		std::priority_queue<int, std::vector<int>> hStones(stones.begin(), stones.end());
		int x = 0, y = 0;

		while (hStones.size() > 1) {
			y = hStones.top();
			hStones.pop();
			x = hStones.top();
			hStones.pop();
			if (x != y) {
				hStones.push(y - x);
			}
			else {
				x = y = 0;
			}
		}
		hStones.push(0);
		return hStones.top();
	}
}

*/