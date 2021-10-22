/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution1 { // 使用词典将原始链表每个节点对应的复制节点记录下来
public:
    unordered_map<Node*, Node*> cachedNode;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        if (!cachedNode.count(head)) {
            Node *node = new Node(head->val);
            cachedNode[head] = node;
            node->next = copyRandomList(head->next);
            node->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};


class Solution2 { // 不使用递归，先将复制的节点固定下来
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        unordered_map<Node*, Node*> cachedNode;
        Node *p = head;
        while (p != nullptr) {
            Node *node = new Node(p->val);
            cachedNode[p] = node;
            p = p->next;
        }
        p = head;
        while (p != nullptr) {
            cachedNode[p]->next = cachedNode[p->next];
            cachedNode[p]->random = cachedNode[p->random];
            p = p->next;
        }
        return cachedNode[head];
    }
};


class Solution3 { // 首先按节点顺序将原始节点和复制节点连接起来，则原始节点的随机指针指向的节点的next指向的就是对应复制节点的随机指针应该指向的节点
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        for (Node *p = head; p != nullptr; p = p->next->next) {
            Node *p_copy = new Node(p->val);
            p_copy->next = p->next;
            p->next = p_copy;
        }

        for (Node *p = head; p != nullptr && p->next != nullptr; p = p->next->next) {
            p->next->random = (p->random != nullptr) ? p->random->next : nullptr;
        }

        Node *newHead = head->next;
        for (Node *p = head; p != nullptr; p = p->next) {
            Node *p_copy = p->next;
            p->next = p_copy->next;
            p_copy->next = (p->next != nullptr) ? p->next->next : nullptr;
        }
        return newHead;
    }
};
