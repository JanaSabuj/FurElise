/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// basecase
		if (head == NULL)
			return head;// empty LL

		if (head->next == NULL)
			return head;// single-node LL

		// main
		ListNode* rev_head = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;

		return rev_head;
	}
};

// ---- iterative
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// base case
		// if (head == NULL || head->next == NULL) return head;
		ListNode *prevNode = NULL, *nextNode;// note - prevNode is NULL and not nextNode [Imp Bug]
		// 1 2 3 4 5
		// ^ ^ n
		// at every index head, you just reverse till head i.e you make it point back to prev
		// prev to curr , then curr to future
		while (head) {
			nextNode = head->next;
			head->next = prevNode;
			prevNode = head;
			head = nextNode;
		}
		return prevNode;
	}
};