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
class Solution1 { // 自顶向下递归使用归并排序：将链表前后半部分分别排序再合并顺序链表
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortListHelper(ListNode* head, ListNode* tail) {
        if (head == nullptr) return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode *p1 = head, *p2 = head;
        while (p1 != tail && p1->next != tail) {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        // ListNode *mid = p2; 
        return merge(sortListHelper(head, p2), sortListHelper(p2, tail));
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy, *p1 = l1, *p2 = l2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            }
            else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1 != nullptr) {
            p->next = p1;
        }
        else {
            p->next = p2;
        }
        return dummy->next;
    }
};


class Solution2 { // 自底向上完成链表的归并排序：首先合并 sublength=1 的链表，再增加 sublength 继续合并
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        int length = 0;
        ListNode *p = head;
        while (p != nullptr) {
            ++length;
            p = p->next;
        }
        ListNode *dummy = new ListNode(-1, head);
        for (int sublength = 1; sublength < length; sublength <<= 1) {
            ListNode *pre = dummy, *cur = dummy->next;
            while (cur != nullptr) {
                ListNode *l1 = cur;
                for (int i = 1; i < sublength && cur->next != nullptr; ++i) {
                    cur = cur->next;
                }
                ListNode *l2 = cur->next;
                cur->next = nullptr;
                cur = l2;

                for (int i = 1; i < sublength && cur != nullptr && cur->next != nullptr; ++i) {
                    cur = cur->next;
                }
                ListNode *next = nullptr;
                if (cur != nullptr) {
                    next = cur->next;
                    cur->next = nullptr;
                    cur = next;
                }

                pre->next = merge(l1, l2);
                while (pre->next != nullptr) {
                    pre = pre->next;
                }
            }
        }
        return dummy->next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy, *p1 = l1, *p2 = l2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            }
            else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1 != nullptr) {
            p->next = p1;
        }
        else {
            p->next = p2;
        }
        return dummy->next;
    }
};
