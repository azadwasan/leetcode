//https://leetcode.com/problems/task-scheduler/
#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Task_Scheduler {
public:
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int>mp;
		int count = 0;
		for (auto e : tasks)
		{
			mp[e]++;
			count = max(count, mp[e]);
		}

		int ans = (count - 1)*(n + 1);
		for (auto e : mp) {
			if (e.second == count) {
				ans++;
			}
		}
		int finalAnswer = max((int)tasks.size(), ans);
		return finalAnswer;
	}
};