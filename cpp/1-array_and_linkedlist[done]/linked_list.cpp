/**
 * File: linked_list.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* 在链表的节点 n0 之后插入节点 P */
// 主要为了建立两条线：
// 1. 建立新节点到原始后继节点的链接
// 2. 建立原始节点到新节点的链接
void insert(ListNode *n0, ListNode *P) {
    // 用一个临时指针 n1 来保存原始后继节点
    ListNode *n1 = n0->next;
    // 将新节点指向原始后继节点
    P->next = n1;
    // 将原始节点指向新节点
    n0->next = P;
}

/* 删除链表的节点 n0 之后的首个节点 */
void remove(ListNode *n0) {
    // 如果A是最后一个节点，那么A后面没有节点可以删除，直接结束
    if (n0->next == nullptr)
        return;
    // n0 -> P -> n1
    // 存储原始后继节点（待删除的节点）
    ListNode *P = n0->next;
    // 存储原始后继节点所指向的下一个节点
    ListNode *n1 = P->next;
    // 直接让当前节点指向原始后继节点的下一个节点，从而跳过了原始后继节点
    n0->next = n1;
    // 释放内存
    delete P;
}

/* 访问链表中索引为 index 的节点 */
ListNode *access(ListNode *head, int index) {
    // 链表的第一个节点的索引为0
    for (int i = 0; i < index; i++) {
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}

/* 在链表中查找值为 target 的首个节点 */
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

/* Driver Code */
int main() {
    /* 初始化链表 */
    // 初始化各个节点
    // n0是一个指针变量，它存储的是内存地址
    // *n0是指针的解引用，代表对象本身
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(5);
    ListNode *n4 = new ListNode(4);
    // 构建节点之间的引用
    // 将一个指针变量赋值给另一个指针变量
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    cout << "初始化的链表为" << endl;
    printLinkedList(n0);

    /* 插入节点 */
    insert(n0, new ListNode(0));
    cout << "插入节点后的链表为" << endl;
    printLinkedList(n0);

    /* 删除节点 */
    remove(n0);
    cout << "删除节点后的链表为" << endl;
    printLinkedList(n0);

    /* 访问节点 */
    ListNode *node = access(n0, 3);
    cout << "链表中索引 3 处的节点的值 = " << node->val << endl;

    /* 查找节点 */
    int index = find(n0, 2);
    cout << "链表中值为 2 的节点的索引 = " << index << endl;

    // 释放内存
    freeMemoryLinkedList(n0);

    return 0;
}
