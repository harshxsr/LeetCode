/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next)
        return head;

    struct ListNode *a = head;
    struct ListNode *b = head->next;

    a->next = swapPairs(b->next);
    b->next = a;

    return b;
}