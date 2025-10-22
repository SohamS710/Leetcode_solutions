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
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> nodeMap;
        ListNode* temp = head;
        while (temp != nullptr) {
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;  // Cycle detected
            }
            nodeMap[temp] = 1;  // Mark node as visited
            temp = temp->next;  // Move to next node
        }
        return false;  // No cycle found
    }
};
