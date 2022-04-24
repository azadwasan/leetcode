#pragma once
//https://leetcode.com/problems/group-anagrams/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <array>

class GroupAnagrams {
public:
	//This is the sorting based solution.
	std::vector<std::vector<std::string>> groupAnagramsSorting(std::vector<std::string>& strs) {
		std::unordered_map<std::string, std::vector<std::string>> map;
		for (auto str : strs) {
			auto copy = str;
			std::sort(copy.begin(), copy.end());
			map[copy].push_back(str);
		}
		std::vector<std::vector<std::string>> result;
		for (auto pair : map) {
			result.push_back(pair.second);
		}
		return result;
	}


	/*	This is an alternate solution where we count the number of each character in the string for the whole alphabat array.
		//However, it is not working and crashes. This is also not the recommended solution in C++ for interview setting.
		//I have already solved the same in JS and available there.

	struct VectorHasher {
		int operator()(const std::vector<int> &V) const {
			int hash = V.size();
			for (auto &i : V) {
				hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
			}
			return hash;
		}
	};

	std::vector<std::vector<std::string>> groupAnagramsArrays(std::vector<std::string>& strs) {
		std::unordered_map<std::vector<int>, std::vector<std::string>, VectorHasher> map;
		for (auto str : strs) {
			std::vector<int> charCount(26);
			for (auto c : str) {
				charCount[c]++;
			}
			map[charCount].push_back(str);
		}
		std::vector<std::vector<std::string>> result;
		for (auto pair : map) {
			result.push_back(pair.second);
		}
		return result;
	}
	*/
};