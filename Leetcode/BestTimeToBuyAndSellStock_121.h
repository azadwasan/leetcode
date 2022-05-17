//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#pragma once
#include <vector>
#include <utility>

class BuyTimeBuySell {
public:

	//Brute force approach...
	int maxProfitBF(std::vector<int>& prices) {
		if (std::size(prices) < 2) {
			return 0;
		}
		int buy = prices[0];
		int sell = -1;
		std::pair<int, int> bestPair{0, 0};

		for (int i = 0; i < std::size(prices)-1; i++) {
			for (int j = i + 1; j < std::size(prices); j++) {
				if ((prices[j] - prices[i]) > (bestPair.second-bestPair.first)) {
					bestPair = { prices[i], prices[j] };
//					std::cout << "Best pair = {" << bestPair.first << ", " << bestPair.second << "}" << std::endl;
				}
			}
		}
		return bestPair.second - bestPair.first;
	}

	//This is a very elegent solution. 
	//It relies on the fact that if profit[l] is less than profit[r], we can keep increasing r
	//As soon as we that is not the case, we have found a new minima, so we shift l to the new low, i.e., 'r'
	//What if the difference that we will find with the new minimum might not be as big as earlier -> It doesn't matter, because we already have a maximum recorded
	//What if there is even a larger number yet to come -> We have found even a smaller number, so we shifted to it.

	int maxProfit(std::vector<int>& prices) {
		int l = 0, r = 1;
		int maxP = 0;
		while (r < std::size(prices)) {
			if (prices[l] < prices[r]) {
				int profit = prices[r] - prices[l];
				maxP = max(maxP, profit);
			}
			else {
				l = r;
			}
			r++;
		}
		return maxP;
	}

	int maxProfitMy(std::vector<int>& prices) {
		if (std::size(prices) < 2) {
			return 0;
		}

		std::pair<int, int> left{ 0, prices[0] };//TODO: Simplify this, just store indices, we can get the values anyway.
		std::pair<int, int> right{ 1, prices[1] };
		std::pair<std::pair<int, int>, std::pair<int,int>> bestPair{ left, right };

		while (left.first<right.first) {
			if (right.first - left.first == 1) {	//If both the pointers are adjescent to each other, the move the right to further right
				if (right.first < std::size(prices) - 1) {
					right = { right.first + 1, prices[right.first + 1] };
				}
				else {
					break;
				}
			}
			else {
				if (right.first < std::size(prices) - 1 && (prices[right.first + 1]-left.second) > (right.second-left.second)) {
						right = { right.first + 1, prices[right.first + 1] };
				}
				else {
					left = { left.first + 1, prices[left.first + 1] };
				}
			}
			if (right.second - left.second > bestPair.second.second - bestPair.first.second) {
				bestPair = { left, right };
			}
		}
		return bestPair.second.second - bestPair.first.second > 0 ? bestPair.second.second - bestPair.first.second : 0;
	}
};