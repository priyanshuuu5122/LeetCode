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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        
        while (current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete; // Important: free memory in C++
            } else {
                // Move to next node
                current = current->next;
            }
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Don't forget to delete dummy node
        return newHead;
    }
};
