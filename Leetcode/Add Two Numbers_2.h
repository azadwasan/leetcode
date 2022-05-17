//May 1, 2022
//https://leetcode.com/problems/add-two-numbers/
#pragma once
#include "LinkedList.h"

//Runtime: 28 ms, faster than 91.75% of C++ online submissions for Add Two Numbers.
//Memory Usage : 70.9 MB, less than 97.50% of C++ online submissions for Add Two Numbers.
class AddTwoNumbers {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *node1 = l1, *node2 = l2, *lastNode1 = node1;
		int carry = 0;
		while (node1 || node2) {
			int num1 = 0, num2 = 0, sum = 0;
			if(node1){
				num1 = node1->val;
				lastNode1 = node1;
				node1 = node1->next;
			}
			else {
				lastNode1->next = new ListNode{ carry };
				lastNode1 = lastNode1->next;
			}
			if (node2) {
				num2 = node2->val;
				node2 = node2->next;
			}
			sum = num1 + num2 + carry;
			carry = (sum - sum % 10) / 10;
			sum %= 10;
			lastNode1->val = sum;
		}
		if (carry != 0) {
			lastNode1->next = new ListNode{carry};
		}
		return l1;
	}
};