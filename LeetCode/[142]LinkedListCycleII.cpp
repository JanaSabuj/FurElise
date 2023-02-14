/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool flag = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                flag = true;
                break;// cycle exists if both ptrs traverse atleast once and then meet (FLoyd's Algorithm)
            }
        }

        if (!flag) return NULL;// no cycle

        ListNode* start = head;// put one end on head, other on the meeting point
        while (start != fast) {
            start = start->next;
            fast = fast->next;
        }

        return fast;
    }
};
