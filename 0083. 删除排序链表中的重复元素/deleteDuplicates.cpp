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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *p1 = head, *p2 = head->next;
        while (p2 != nullptr) {
            if (p2->val == p1->val) {
                p2 = p2->next;
                p1->next = p2;
            }
            else {
                // p1->next = p2;
                p1 = p2;
                p2 = p2->next;
            }
        }
        return head;
    }
};
