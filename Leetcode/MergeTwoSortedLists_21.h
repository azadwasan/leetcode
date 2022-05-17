#pragma once
#include "LinkedList.h"
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class MergeSortedLists {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* n1 = list1; ListNode* n2 = list2;
		ListNode* res = nullptr;
		if (!n1) {
			return n2;
		}
		if (!n2) {
			return n1;
		}

		if (n1->val <= n2->val) {
			res = n1;
		}
		else {
			res = n2;
		}

		while (n1 && n2) {
			if (n1->val == n2->val) {
				if (n1->next && n1->val == n1->next->val) {
					n1 = n1->next;
				}
				else {
					ListNode* temp = n1->next;
					n1->next = n2;
					n1 = temp;
				}
			}
			else if (n1->val < n2->val) {
				if (n1->next && n1->next->val <= n2->val) {	//Before we point to the n2 element, we need to make sure, next element in the L1 is not smaller than n2
					n1 = n1->next;
				}
				else {
					ListNode* temp = n1->next;
					n1->next = n2;
					n1 = temp;
				}
			}
			else if (n1->val > n2->val) {
				if (n2->next && n1->val > n2->next->val) {
					n2 = n2->next;
				}
				else {
					ListNode* temp = n2->next;
					n2->next = n1;
					n2 = temp;
				}
			}
		}
		return res;
	}
};