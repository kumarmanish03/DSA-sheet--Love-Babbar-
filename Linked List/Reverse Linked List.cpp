/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://leetcode.com/problems/reverse-linked-list/
* @TC: O(N)
*
*/

// Iterative
ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *ans = head, *cur = head;
        head = head->next;
        cur->next = NULL;
        while(head){
            cur = head;
            head = head->next;
            cur->next = ans;
            ans = cur;
        }
        return ans;
    }

// Recursive
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next)
        return head;
    
    ListNode *ans = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return ans;
}