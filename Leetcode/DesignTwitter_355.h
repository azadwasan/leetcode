#pragma once
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <chrono>

struct Tweet {
	Tweet(int tweetid) :tweetId{ tweetid }, time{ std::chrono::high_resolution_clock::now() }{}
	int tweetId;
	std::chrono::time_point<std::chrono::high_resolution_clock> time;
};

class User {
public:
	void postTweet(int tweetId) {
		tweets.push_back(Tweet(tweetId));
	}

	std::vector<Tweet> getNewsFeed() {
		std::vector<Tweet> first_ten;
		int feedLength = FEED_LENGTH;
		if (feedLength > tweets.size()) {
			feedLength = tweets.size();
		}

		std::copy(tweets.end()-feedLength, tweets.end(), std::back_inserter(first_ten));
		return first_ten;
	}

	void follow(int followeeId) {
		follows.push_back(followeeId);
	}

	void unfollow(int followeeId) {
		for (auto iter = follows.begin(); iter != follows.end(); iter++){
			if (*iter == followeeId) {
				follows.erase(iter);
				return;
			}
		}
	}

	const std::vector<int>& getFollows() {
		return follows;
	}

private:
	static const int FEED_LENGTH = 10;
	std::vector<Tweet> tweets;
	std::vector<int> follows;
};

class CompareTweet {
public:
	bool operator()(const Tweet& left, const Tweet& right) { return (right.time - left.time).count() > 0; }
};

class Twitter {
public:
	Twitter(){}
	~Twitter() {
		for (auto iter = users.begin(); iter != users.end(); iter++) {
			delete iter->second;
		}
	}
	void postTweet(int userId, int tweetId) {
		auto user = getUser(userId);
		user->postTweet(tweetId);
	}

	std::vector<int> getNewFeed(int userId) {
		auto cmp = [](const Tweet& left, const Tweet& right) {return (right.time - left.time).count() > 0; };
//		std::priority_queue<Tweet, std::vector<Tweet>, decltype(cmp)> queue(cmp);
		std::priority_queue<Tweet, std::vector<Tweet>, CompareTweet> queue{};

		auto user = getUser(userId);
		addToQueue(user->getNewsFeed(), queue);

		for (auto follow : user->getFollows()) {
			addToQueue(getUser(follow)->getNewsFeed(), queue);
		}

		std::vector<int> top_ten;
		while (!queue.empty() && top_ten.size() < 10) {
			top_ten.push_back(queue.top().tweetId);
			queue.pop();
		}
		return top_ten;
	}

	void follow(int followerId, int followeeId) {
		getUser(followeeId);	//Call this to make sure the user is created
		auto user = getUser(followerId);
		user->follow(followeeId);
	}

	void unfollow(int followerId, int followeeId) {
		auto user = getUser(followerId);
		user->unfollow(followeeId);
	}

	/* Internal Methods */
private:
	User* getUser(int userId) {
		auto iter = users.find(userId);
		if (iter == users.end()) {
			auto newUser = new User();
			users[userId] = newUser;
			return newUser;
		}
		return iter->second;
	}

	//template<class T>
	//void addToQueue(const std::vector<Tweet>& feed, T& queue) {
	//	for (auto tweet : feed) {
	//		queue.push(tweet);
	//	}
	//}

	void addToQueue(const std::vector<Tweet>& feed, std::priority_queue<Tweet, std::vector<Tweet>, CompareTweet>& queue) {
		for (auto tweet : feed) {
			queue.push(tweet);
		}
	}



	/* Data Members */
private:
	std::map<int, User*> users;
};