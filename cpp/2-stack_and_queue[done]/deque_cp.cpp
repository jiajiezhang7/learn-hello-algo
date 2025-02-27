#include "../utils/common.hpp"

int main(){
    deque<int> deque;

    deque.push_back(2);
    deque.push_back(5);
    deque.push_back(4);
    deque.push_front(3);
    deque.push_front(1);

    cout << "deque = ";
    printDeque(deque);

    int front = deque.front();
    cout << "front = " << front << endl;
    int back = deque.back();
    cout << "back = " << back << endl;

    deque.pop_front();
    cout << "popFront = " << front <<", after popfront, deque = ";
    printDeque(deque);

    deque.pop_back();
    cout << "popLast = " << back << ", after poplast, deque = ";
    printDeque(deque);

    int size = deque.size();
    cout << "deque size = " << size << endl;

    bool empty = deque.empty();
    cout << "is deque empty? = " << empty << endl;

    return 0;
}