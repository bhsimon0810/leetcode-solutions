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
class Solution1 { // 找到链表中点前的一个节点，然后对后半部分链表反转，再合并两个链表。注意函数返回值为void，说明需要对输入的链表进行操作，不支持dummy节点
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *p1 = head, *p2 = head;
        while (p1->next != nullptr && p1->next->next != nullptr) {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        return p2;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *pre = nullptr, *cur = head, *next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    void merge(ListNode* l1, ListNode* l2) {
        ListNode *p1, *p2;
        while (l1 != nullptr && l2 != nullptr) {
            p1 = l1->next;
            p2 = l2->next;
            l1->next = l2;
            l2->next = p1;
            l1 = p1;
            l2 = p2;
        }
    }

    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode *mid = middleNode(head);
        ListNode *l1 = head;
        ListNode *l2 = reverse(mid->next);
        mid->next = nullptr;
        merge(l1, l2);
    }
};


class Solution2 { // 将链表节点储存在 vector 中然后可以线性操作节点
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        vector<ListNode*> vec;
        ListNode *p = head;
        while (p != nullptr) {
            vec.emplace_back(p);
            p = p->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            if (++i >= j) break; 
            vec[j]->next = vec[i];
            --j;
        }
        vec[i]->next = nullptr;
        return;
    }
};


class Solution3 { // 递归解法，后序遍历，链表头节点->尾节点再循环往复
public:
    ListNode *temp;
    bool isStop;

    void reorderListHelper(ListNode* head) {
        if (head == nullptr) return;
        reorderListHelper(head->next);

        if(!isStop) {
            ListNode *next = temp->next;
            temp->next = head;
            head->next = next;
            temp = next;
        }

        if(temp != nullptr && temp->next == head) {
            temp->next = nullptr;
            isStop = true;
        }
    }

    void reorderList(ListNode* head) {
        temp = head;
        isStop = false;
        reorderListHelper(head);
    }
};
