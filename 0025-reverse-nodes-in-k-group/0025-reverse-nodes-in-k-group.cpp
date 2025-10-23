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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes remaining
        ListNode* node = head;
        int count = 0;
        while (node != nullptr && count < k) {
            node = node->next;
            count++;
        }

        // If less than k nodes remain, return head (no reversal)
        if (count < k) return head;

        // Step 2: Reverse exactly k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int i = 0;

        while (curr != nullptr && i < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }

        // Step 3: Recursively reverse the remaining list
        // 'head' is now the tail of the reversed group
        head->next = reverseKGroup(curr, k);

        // 'prev' is the new head of the current reversed group
        return prev;
    }
};
