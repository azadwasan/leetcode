#pragma once

#include <vector>
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class LinkedList {
public:
	static ListNode* makeLL(std::vector<int>& values) {
		ListNode* head = new ListNode(values[0]);
		ListNode* node = head;
		for (int i = 1; i < std::size(values); i++) {
			node->next = new ListNode{ values[i] };
			node = node->next;
		}
		return head;
	}

	static void printLL(ListNode* head) {
		ListNode* node = head;
		while (node) {
			std::cout << node->val << "  ->  ";
			node = node->next;
		}
		std::cout << std::endl;
	}
};




//template <class T>
//class NodeList{
//public:
//	NodeList(T v, NodeList* n = nullptr) : val(v), next(n) {}
//	T val;
//	NodeList* next;
//	~NodeList() {
//		delete next;
//		next = nullptr;
//	}
//};

//class LinkedList {
//public:
//	static NodeList<int>* makeLL(std::vector<int>& values) {
//		NodeList<int>* head = new NodeList<int>(values[0]);
//		NodeList<int>* node = head;
//		for (int i = 1; i < std::size(values); i++) {
//			node->next = new NodeList<int>{ values[i] };
//			node = node->next;
//		}
//		return head;
//	}
//	static void printLL(NodeList<int>* head) {
//		NodeList<int>* node = head;
//		while (node) {
//			std::cout << node->val << "  ->  ";
//			node = node->next;
//		}
//		std::cout << std::endl;
//	}
//};
