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
class Solution1 { // 利用链表的后序遍历，首先使用全局变量保存头节点，然后遍历到尾节点进行判断。注意如果是判断是否回文则从两端到中间，如果寻找回文子串则从中间到两端
public:
    ListNode *left = nullptr;

    bool isPalindrome(ListNode* head) {
        left = head;
        return isPalindromeHelper(left);
    }

    bool isPalindromeHelper(ListNode* right) {
        if (right == nullptr) return true;
        bool ans = isPalindromeHelper(right->next);
        ans = ans && (left->val == right->val);
        left = left->next;
        return ans;
    }
};


class Solution2 { // 找到后半部分链表进行反转再判断
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return false;
        if (head->next == nullptr) return true;
        ListNode *p1 = head;
        ListNode *p2 = reverse(middleNode(p1));
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val == p2->val) {
                p1 = p1->next;
                p2 = p2->next;
            }
            else {
                return false;
            }
        }
        return true;
    }

    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *p1 = head, *p2 = head;
        while (p1 != nullptr && p1->next != nullptr) {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        // 返回后半部分链表的起始节点
        return (p1 != nullptr) ? p2->next : p2;
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *pre = nullptr, *cur = head, *next = head;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
};
