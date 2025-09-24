/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = head;

    struct ListNode* curr = temp;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode* temp1 = curr->next;
            curr->next = curr->next->next;
            free(temp1);
        } else {
            curr = curr->next;
        }
    }
    struct ListNode* new = temp->next;
    free(temp);
    return new;
}