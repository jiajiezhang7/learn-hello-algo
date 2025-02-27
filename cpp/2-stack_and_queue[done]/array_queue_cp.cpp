// 用数组实现队列，内部数据结构为数组vector，外部表现为queue，自定义封装了queue的方法

#include "../utils/common.hpp"

class ArrayQueue {
    private:
        int *nums;
        int front;   //队首指针，指向队首元素
        int queSize; //队列实际长度
        int queCapacity; //队列容量

    public:
        ArrayQueue(int capacity) {
            nums = new int[capacity];
            queCapacity = capacity;
            front = queSize = 0;
        }

        ~ArrayQueue() {
            delete[] nums;
        }
        
        int capacity() {
            return queCapacity;
        }

        int size() {
            return queSize;
        }

        bool isEmpty() {
            return size() == 0;
        }

        void push(int num) {
            if (queSize == queCapacity) {
                cout << "queue is full!" << endl;
                return;
            }

            // 循环队列的实现，确保充分利用数组空间
            int rear = (front + queSize) % queCapacity;

            nums[rear] = num;
            queSize++;
        }

        int pop() {
            int num = peek();
            front = (front + 1) % queCapacity;
            queSize --;
            return num;
        }

        int peek() {
            if (isEmpty())
                throw out_of_range("queue is empty!");
            return nums[front];
        }

        vector<int> toVector() {
            vector<int> arr(queSize);
            for (int i = 0, j = front; i < queSize; i++, j++) {
                arr[i] = nums[j % queCapacity];
            }
            return arr;
        }
};

int main() {
    int capacity = 10;
    ArrayQueue *queue = new ArrayQueue(capacity);

    queue->push(1);
    queue->push(3);
    queue->push(2);
    queue->push(5);
    queue->push(4);
    cout << "queue = ";
    printVector(queue->toVector());

    // 访问队首元素，由front下标所指明
    int peek = queue->peek();
    cout << "peek = " << peek <<endl;

    peek = queue->pop();
    cout << "pop element = " << peek << ", after pop, new queue = ";
    printVector(queue->toVector());

    int size = queue->size();
    cout << "queue size = " << size << endl;

    bool empty = queue->isEmpty();
    cout << "is queue empty? = " << empty << endl;

    for (int i = 0; i < 10; i ++) {
        queue->push(i);
        queue->pop();
        cout << "this is the No." << i << " turns push/pop, and queue = ";
        printVector(queue->toVector());
    }

    delete queue;

    return 0;
}