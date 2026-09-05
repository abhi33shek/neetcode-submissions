class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        
        return prev;
    }
};