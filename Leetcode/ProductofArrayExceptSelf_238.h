#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <numeric>

// https://leetcode.com/problems/product-of-array-except-self/
//Basically it is a very simple problem but the requirements make it pretty hard.
//All we had to do is multiply all numbers and then divide by each number to generate the final result.
//	Though we need to take care of two edge cases, if there is a zero, it should result all zero, except the zero position and two zeroes will results in all being zero.
//However, it is not allowed to to use division operator.
//Second simple approach would be to have a nested loop and calculate the results but then the complexicty would be O(n^2) and requirement is O(n)


//Really excellent solutions
//https://leetcode.com/problems/product-of-array-except-self/discuss/1597994/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Prefix-and-Suffix-product-O(1)-space-approach
class ProductOfArrayExceptSelf {
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums) {
		if (std::size(nums) <= 1) {
			return {};
		}
		std::vector<int> prefix(std::size(nums));
		std::vector<int> postfix(std::size(nums));
		prefix[0] = 1;
		postfix[std::size(postfix) - 1] = 1;
		int mul = 1;
		for (int i = 1; i < std::size(nums);i++) {
			mul *= nums[i - 1];
			prefix[i] = mul;
		}
		mul = 1;
		for (int i = std::size(nums) - 2; i >= 0; i--) {
			mul *= nums[i + 1];
			postfix[i] = mul;
		}

		std::vector<int> result(std::size(nums));
		for (int i = 0; i < std::size(nums); i++) {
			result[i] = prefix[i] * postfix[i];
		}
		return result;
	}

	std::vector<int> productExceptSelf2(std::vector<int>& nums) {
		vector<int> pre(nums), suf(nums), ans(size(nums));
		partial_sum(begin(pre), end(pre), begin(pre), multiplies<int>());       // calculates & stores prefix product at each index
		partial_sum(rbegin(suf), rend(suf), rbegin(suf), multiplies<int>());    // calculates & stores suffix product at each index
		for (int i = 0; i < size(nums); i++)
			ans[i] = (i ? pre[i - 1] : 1) * (i + 1 < size(nums) ? suf[i + 1] : 1);
		return ans;
	}

	template <class T>
	void printVector(const std::vector<T>& vec) {
		std::cout << "*************************" << std::endl;
		for (auto val : vec) {
			std::cout << val << std::endl;
		}
	}
};