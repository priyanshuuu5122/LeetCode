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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*curr=head;
        for(int i=0;i<n;i++){
            curr=curr->next;
        }
        if(!curr) return head->next;
        ListNode*start = head;
        while(curr->next){
            curr = curr->next;
            start = start->next;
        }
        start->next=start->next->next;
        return head;
    }
};

        
   
        
        
    
