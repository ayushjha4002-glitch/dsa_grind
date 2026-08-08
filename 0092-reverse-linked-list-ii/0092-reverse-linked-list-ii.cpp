class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* before = NULL;
        ListNode* t = head;

        for(int pos = 1; pos < left; pos++) {
            before = t;
            t = t->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = t;

        for(int i = 0; i < right - left + 1; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        t->next = curr;

        if(before == NULL)
            head = prev;
        else
            before->next = prev;

        return head;
    }
};