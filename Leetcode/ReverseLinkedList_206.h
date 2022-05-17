//https://leetcode.com/problems/reverse-linked-list/
#pragma once

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ReverseLinkedList {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* previous = nullptr;
		ListNode* curr = head;
		while (curr) {
			ListNode* temp = curr->next;
			curr->next = previous;
			previous = curr;
			curr = temp;
		}
	}
};