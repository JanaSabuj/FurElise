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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;// slow moves 1 pt
            fast = fast->next->next;// fast moves 2 pts
        }

        return slow;// in both the cases fast == NULL and fast->next == NULL, return slow - draw and check
    }
};
// TC: O(N), SC: O(1)