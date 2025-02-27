// 基于链表实现队列

#include "../utils/common.hpp"

class LinkedListQueue {
    private:
        ListNode *front, *rear;
        int queSize;

    public:
        LinkedListQueue() {
            front = nullptr;
            rear = nullptr;
            queSize = 0;
        }

        ~LinkedListQueue() {
            freeMemoryLinkedList(front);
        }

        int size() {
            return queSize;
        }

        bool isEmpty(){
            return queSize == 0;
        }

        // 元素入队
        void push(int num) {
            ListNode *node = new ListNode(num);
            if (front == nullptr) {
                front = node;
                rear = node;
            }else {
                rear->next = node;
                rear = node;
            }
            queSize++;
        }

        // 元素出队（先进先出，front先出）
        int pop() {
            int num = peek();

            ListNode *tmp = front;
            front = front->next;
            delete tmp;
            queSize --;
            return num;
        }

        // 访问队首元素
        int peek() {
            if (size() == 0)
                throw out_of_range("queue is empty!");
            return front->val;
        }

        vector<int> toVector() {
            ListNode *node = front;
            vector<int> res(size());
            for(int i = 0; i < res.size(); i++) {
                res[i] = node->val;
                node = node->next;
            }
            return res;
        }
};

int main() {
    LinkedListQueue *queue = new LinkedListQueue();

    queue->push(1);
    queue->push(3);
    queue->push(2);
    queue->push(5);
    queue->push(4);
    cout << "queue = ";
    printVector(queue->toVector());

    int peek = queue->peek();
    cout << "peek = " << peek << endl;

    peek = queue->pop();
    cout << "pop = " << peek << ", after pop, queue = ";
    printVector(queue->toVector());

    int size = queue->size();
    cout << "queue size = " << size << endl;

    bool empty = queue->isEmpty();
    cout << "is queue empty?= " << empty << endl;

    delete queue;

    return 0;
}

