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
        // 借助 dummy 保证链表头节点为不重复元素
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy;
        while (p->next != nullptr && p->next->next != nullptr) {
            if (p->next->val == p->next->next->val) {
                int val = p->next->val;
                while (p->next != nullptr && p->next->val == val) {
                    p->next = p->next->next;
                }
            }
            else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};
