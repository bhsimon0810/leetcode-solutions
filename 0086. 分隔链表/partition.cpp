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
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallDummy = new ListNode(-1, head);
        ListNode *largeDummy = new ListNode(-1, head);
        ListNode *p = head, *sp = smallDummy, *lp = largeDummy;
        while (p != nullptr) {
            if (p->val < x) {
                sp->next = p;
                sp = sp->next;
            }
            else {
                lp->next = p;
                lp = lp->next;
            }
            p = p->next;
        }
        lp->next = nullptr;
        sp->next = largeDummy->next;
        return smallDummy->next;
    }
};
