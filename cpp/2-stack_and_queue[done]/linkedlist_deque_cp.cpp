#include "../utils/common.hpp"

// 双向链表节点
struct DoublyListNode {
    int val;
    DoublyListNode *next;
    DoublyListNode *prev;
    DoublyListNode(int val): val(val), prev(nullptr), next(nullptr){

    }
};

// 基于双向链表实现的双向队列
class LinkedListDeque {
    private:
        DoublyListNode *front, *rear;
        int queSize = 0;

    public:
        LinkedListDeque() : front(nullptr), rear(nullptr) {

        }
        ~LinkedListDeque() {
            DoublyListNode *pre, *cur = front;
            while (cur != nullptr) {
                pre = cur;
                cur = cur->next;
                delete pre;
            }
        }

        int size() {
            return queSize;
        }

        bool isEmpty() {
            return size() == 0;
        }

        void push(int num, bool isFront) {
            DoublyListNode *node = new DoublyListNode(num);

            if (isEmpty())
                front = rear = node;
            else if (isFront) {
                front->prev = node;
                node->next = front;
                front = node;
            } else {
                rear->next = node;
                node->prev = rear;
                rear = node;
            }
            queSize ++;
        }

        void pushFirst(int num) {
            push(num, true);
        }

        void pushLast(int num) {
            push(num, false);
        }

        int pop(bool isFront) {
            if (isEmpty())
                throw out_of_range("deque is empty!");
            int val;
            if (isFront) {
                val = front->val;

                DoublyListNode *fNext = front->next;
                if (fNext != nullptr) {
                    fNext->prev = nullptr;
                    front->next = nullptr;
                }
                delete front;
                front = fNext;
            } else {
                val = rear->val;
                DoublyListNode *rPrev = rear->prev;
                if (rPrev != nullptr) {
                    rPrev->next = nullptr;
                    rear->prev = nullptr;
                }
                delete rear;
                rear = rPrev;
            }
            queSize--;
            return val;
        }

        int popFirst() {
            return pop(true);
        }

        int popLast() {
            return pop(false);
        }

        int peekFirst() {
            if (isEmpty())
                throw out_of_range("deque is empty!");
            return front->val;
        }

        int peekLast() {
            if (isEmpty())
                throw out_of_range("deque is empty!");
            return rear->val;
        }

        vector<int> toVector() {
            DoublyListNode *node = front;
            vector<int> res(size());
            for (int i = 0; i < res.size(); i++) {
                res[i] = node->val;
                node = node->next;
            }
            return res;
        }
};