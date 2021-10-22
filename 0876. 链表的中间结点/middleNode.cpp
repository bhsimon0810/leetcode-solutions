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
    ListNode* middleNode(ListNode* head) {
        ListNode *p1 = head, *p2 = head;
        while (p1 != nullptr && p1->next != nullptr) {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        return p2;
    }
};
