// 队列 --- 排队 --- 先进先出

#include "../utils/common.hpp"

int main() {
    queue<int> queue;

    queue.push(1);
    queue.push(3);
    queue.push(2);
    queue.push(5);
    queue.push(4);
    cout << "queue = ";
    printQueue(queue);

    int front = queue.front();
    cout << "front = " << front << endl;

    queue.pop();
    cout << "pop front = " << front << "after pop, new queue = ";
    printQueue(queue);

    int size = queue.size();
    cout << "queue size = " << size << endl;
    
    bool empty = queue.empty();
    cout << "is queue empty? = " << empty << endl;

    return 0;
}