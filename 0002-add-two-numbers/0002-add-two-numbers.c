/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* create(int val) {
    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->val = val;
    new->next = NULL;
    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = create(0);
    struct ListNode* current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        } 
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum/10;
        current->next = create(sum%10);
        current = current->next;
    }
    return dummy->next;
}