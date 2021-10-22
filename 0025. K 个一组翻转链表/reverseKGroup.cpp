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
class Solution { // 链表的前序遍历
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < k; ++i) {
            if (p2 == nullptr) return head;
            p2 = p2->next;
        }
        ListNode *newHead = reverse(p1, p2);
        p1->next = reverseKGroup(p2, k);
        return newHead;
    }

    // 反转 head 和 tail 之间的链表
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode *pre = nullptr, *cur = head, *next = head;
        while (cur != tail) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
