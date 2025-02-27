#include "../utils/common.hpp"

// 在链表的节点 n0 之后插入节点 P
void insert(ListNode *n0, ListNode *P) {
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

// 删除链表的节点 n0 之后的首个节点
void remove(ListNode *n0) {
    // 如果n0是尾节点则不必操作
    if (n0->next == nullptr)
        return;
    // 存储原始后继节点（待删除的节点）
    ListNode *P = n0->next;
    // 存储原始后继节点所指向的下一个节点
    ListNode *n1 = P->next;
    // 直接让当前节点指向原始后继节点的下一个节点，从而跳过了原始后继节点
    n0->next = n1;
    delete P;
}

// 访问链表中索引为index的节点
ListNode *access(ListNode *head, int index) {
    for(int i = 0; i < index; i++){
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}

// 在链表中查找值为 target 的首个节点
int find(ListNode *head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

int main() {
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(5);
    ListNode *n4 = new ListNode(4);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printLinkedList(n0);
}