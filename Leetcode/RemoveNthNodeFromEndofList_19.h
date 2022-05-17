//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#pragma once
#include "LinkedList.h"

class RemoveNthNodeFromEndofList {
public:

	//This solution is 100% faster than others.
	//Here is the basic idea behind it
	//	https ://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/1164542/JS-Python-Java-C%2B%2B-or-Easy-Two-Pointer-Solution-w-Explanation
	//The idea can be summarized as follows:
	//  1. Add a dummy node to get a start even before the start of LL, so that if we have to delete even the first element we can do it
	//  2. Take two pointers, fast and slow.
	//  3. Give fast a head start where it goes n steps ahead
	//  4. Now, loop to the end of the LL and increment both slow and fast.
	// When we will reach the end of LL with fast pointer, slow will be n steps behind. Actually one step more, beacuse we started with dummy, which lets up delete the node that we wanted, otherwise we would be on top of the node that we wanted to delete.
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* slow = dummy;
		ListNode* fast = head;
		while (n > 0 && fast) {
			n--;
			fast = fast->next;
		}
		while (fast) {
			fast = fast->next;
			slow = slow->next;
		}
		ListNode* temp = slow->next;
		slow->next = slow->next->next;
		delete temp;
		return dummy->next;
	}












	//This is my apporach but it is actually inefficient, as we need to make two passes. Hence, the solution above resolves the issue in one pass.
	ListNode* removeNthFromEndTwoPasses(ListNode* head, int n) {
		ListNode* node = head;
		int length = findLLLength(head);
		if (n == length) {
			ListNode* temp = head;
			head = head->next;
			delete temp;
			return head;
		}		//Note about the node to be fetched: If we have to fetch node 2 from the end
		else { //then we need to access one node before it. Say length is 5 and 2nd from end is to be deleted, then 5-2 = 3 is already what we want. However, we need to additionally subtract 1.
			ListNode* ele = getElement(head, length - n -1); // -1 because, when we try to fetch the 5-2=3 element, before the loop fails, in the last cycle, the node has already moved to the next element. Hence, we stop it one step before so we have the right element.
			if (ele) {		//Otherwise, we get node '4' and not 3.
				ListNode* temp = ele->next;
				ele->next = ele->next->next;
				delete temp;
			}
		}
		return head;
	}

	ListNode* getElement(ListNode* head, int index) {
		int i = 0;
		ListNode* node = head;
		while (node && i<index) {
			i++;
			node = node->next;
		}
		return node;
	}

	int findLLLength(ListNode* head) {
		ListNode* node = head;
		int counter = 0;
		while (node) {
			counter++;
			node = node->next;
		}
		return counter;
	}
};