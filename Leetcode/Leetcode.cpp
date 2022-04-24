// Leetcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "LastStoneWeight_1046.h"
#include "KthLargestElementinaStream_703.h"
#include "KClosestPointstoOrigin_973.h"
#include "KthLargestElement.h"
#include "Task_Scheduler_621.h"
#include <algorithm>
#include <iterator>
#include <chrono>
#include "DesignTwitter_355.h"
#include "TopKFrequentElements_347.h"
#include "GroupAnagrams_49.h"
#include "ProductofArrayExceptSelf_238.h"
#include "EncodeDecodeString_659.h"
#include "LongestConsectiveSequence.h"
#include "FindDuplicateNumber_287.h"
#include "Valid_Palindrome_125.h"

template <class T>
void printVector(const std::vector<T>& vec);

int main()
{
/*	LastStoneWeight_1046
//	std::vector<int> stones{ 2, 7, 4, 1, 8, 1 };
	std::vector<int> stones{ 1, 3 };
	SlashingStones slashStones{};
	slashStones.lastStoneWeight(stones);

*/

/* KthLargestElementinaStream_703
	std::vector<int> stream{};
	KthLargest kthLar{ 1, stream };
	std::cout << kthLar.add(-3) << std::endl;
	std::cout << kthLar.add(-2) << std::endl;
	std::cout << kthLar.add(-4) << std::endl;
	std::cout << kthLar.add(0) << std::endl;
	std::cout << kthLar.add(4) << std::endl;
	
	//std::vector<int> stream{ 4, 5, 8, 2 };
	//KthLargest kthLar{ 3, stream };
	//std::cout << kthLar.add(3) << std::endl;
	//std::cout << kthLar.add(5) << std::endl;
	//std::cout << kthLar.add(10) << std::endl;
	//std::cout << kthLar.add(9) << std::endl;
	//std::cout << kthLar.add(4) << std::endl;
*/
/*
//	std::vector<std::vector<int>> points{ {1,3}, {-2,2} };
	std::vector<std::vector<int>> points{ {3,3}, {5,-1}, {-2, 4} };
	KClosestPointsToOrigin kPoints{};
	auto result = kPoints.kClosest(points, 2);
	kPoints.displayVector(result);
*/

/*KthLargestElement
	std::vector<int> nums{ 3, 2, 1, 5, 6, 4 };
	KthLargestElement kLar{};
//	kLar.findKethLargestSorting(nums, 2);
	kLar.findKthLargestHeap(nums, 2);
*/
/* Task_Scheduler 
	std::vector<char> tasks{ 'A', 'B', 'A','B','A','C' };
	Task_Scheduler ts{};
	std::cout << ts.leastInterval(tasks, 2) << std::endl;
*/

/*	std::vector<int> values;
	values.push_back(5);
	values.push_back(15);
	values.push_back(25);
	values.push_back(35);
	std::vector<int> sub_vector{};
	std::copy(values.end()-2, values.end(), sub_vector.begin());
	for (auto val : sub_vector) {
		std::cout << val << std::endl;
	}
	*/

/*	auto start_time = std::chrono::high_resolution_clock::now();
//	Sleep(500);
	for (int i = 0; i < 300000; i++) {}
	auto end_time = std::chrono::high_resolution_clock::now();
	std::cout << (start_time - end_time).count() << std::endl;
	std::cout << (chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count()) << std::endl;
	*/

	/*
	Twitter t;
	t.postTweet(1, 5);
	
	auto feed = t.getNewFeed(1);
	printVector(feed);
	
	t.follow(1, 2);

	t.postTweet(2, 6);

	feed = t.getNewFeed(1);
	printVector(feed);

	t.unfollow(1, 2);

	feed = t.getNewFeed(1);
	printVector(feed);
	*/

	/*
	TopKFrequentElements topK{};
	std::vector<int> nums{ 1, 1, 1, 2, 2, 3 };
	printVector(topK.topKFrequent(nums, 2));
	*/
	/*
	std::vector<std::string> words{ "eat", "tea", "tan", "ate", "nat", "bat" };

	GroupAnagrams anagrams;
	auto result = anagrams.groupAnagramsSorting(words);
//	auto result = anagrams.groupAnagramsArrays(words);
	for (auto vec1 : result) {
		std::cout << "[";
		for (auto str: vec1) {
			std::cout << str << ", ";
		}
		std::cout << "]" << std::endl;
	}
	//printVector(anagrams.groupAnagramsSorting(words));
	*/
/*
	ProductOfArrayExceptSelf product;
//	std::vector<int> nums{ 1, 2, 3, 4 };
//	std::vector<int> nums{ 2, 3};
//	std::vector<int> nums{ 1, -2, 3, -4 };
	std::vector<int> nums{ 2};
//	printVector(product.productExceptSelf(nums));
	printVector(product.productExceptSelf2(nums));
	*/

/*
	EncodeDecodeString enDe{};
	std::vector<std::string> strs { "li;;nt","co;de",";love",";y;ou;" };
	std::string resultStr = enDe.encode(strs);
	std::vector<std::string> result = enDe.decode(resultStr);

	printVector(result);

	*/

/*
	std::vector<int> nums{ 100,4,200,1,3,2 };
//	std::cout <<  LongestConsectiveSequence{}.longestConsecutive(nums) <<std::endl;
	std::cout << LongestConsectiveSequence{}.longestConsectiveUnordered(nums) << std::endl;
*/
/*
///	std::vector<int> nums{ 1,3,4,2,2 };
//	std::vector<int> nums{ 2, 2, 2, 2, 2 };
//	std::vector<int> nums{ 1,1 };
	std::vector<int> nums{ 1, 3, 4, 2, 2 };

	std::cout<< DuplicateNumber{}.findDuplicate_fastSlow(nums)<<std::endl;
*/
	std::string str{ "A man, a plan, a canal : Panama" };
	std::cout << ValidPalindrome{}.isPalindrome(str) << std::endl;

}

template <class T>
void printVector(const std::vector<T>& vec) {
	std::cout << "*************************" << std::endl;
	std::cout << "Vector size = " << vec.size() << std::endl;

	for (auto val : vec) {
		std::cout << val << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
