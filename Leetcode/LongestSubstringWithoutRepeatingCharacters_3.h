//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#pragma once
#include <string>
#include <algorithm>

class LongestSubstring {
public:
	int lengthOfLongestSubstring(std::string& s) {
		if (std::size(s) < 1) { return 0; }

		int maxL = 1;
		int l = 0;
		int r = 1;
		while (r < std::size(s)) {
			while (containsBtwLR(s, l, r-1, s[r])) {
				l++;
			}
			maxL = std::max(maxL, r - l + 1);
			r++;
		}
		return maxL;
	}

	bool containsBtwLR(std::string& s, int l, int r, char c) {
		for (int i = l; i <= r; i++) {
			if (s[i] == c) {
				return true;
			}
		}
		return false;
	}
};