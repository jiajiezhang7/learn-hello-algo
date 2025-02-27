#include "../utils/common.hpp"

void testPush(priority_queue<int> &heap, int val) {
    heap.push(val);
    cout << "after " << val << " into heap:" << endl;
    printHeap(heap);

}

void testPop(priority_queue<int> &heap) {
    int val = heap.top();
    heap.pop();
    cout << "\n heap head: " << val << "out of heap: " << endl;
    printHeap(heap);
}

int main() {
    priority_queue<int, vector<int>, less<int>> maxHeap;

    cout << "\n for maxHeap test: " << endl;

    testPush(maxHeap, 1);
    testPush(maxHeap, 3);
    testPush(maxHeap, 2);
    testPush(maxHeap, 5);
    testPush(maxHeap, 4);

    int peek = maxHeap.top();
    cout <<"\n heap head is: " << peek << endl;

    testPop(maxHeap);
    testPop(maxHeap);
    testPop(maxHeap);
    testPop(maxHeap);
    testPop(maxHeap);

    int size = maxHeap.size();
    cout << "heap elements counts: " << size <<endl;

    bool isEmpty = maxHeap.empty();
    cout << "\n is heap empty?= " << isEmpty << endl;

    vector<int> input{1, 3, 2, 5, 4};
    priority_queue<int, vector<int>, greater<int>> minHeap(input.begin(), input.end());
    cout << "after input list and build minHeap: " << endl;
    printHeap(minHeap);

    return 0;

}