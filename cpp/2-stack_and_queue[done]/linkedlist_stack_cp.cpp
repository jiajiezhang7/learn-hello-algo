// 用链表实现栈

#include "../utils/common.hpp"

class LinkedListStack {
    private:
        ListNode *stackTop;
        int stkSize;

    public:
        LinkedListStack() {
            stackTop = nullptr;
            stkSize = 0;
        }

        ~LinkedListStack() {
            freeMemoryLinkedList(stackTop);
        }

        int size() {
            return stkSize;
        }

        bool isEmpty() {
            return size() == 0;
        }

        // 入栈，新节点为最新的栈顶
        void push(int num) {
            ListNode *node = new ListNode(num);
            node->next = stackTop;
            stackTop = node;
            stkSize++;
        }

        int pop() {
            int num = top();
            // 临时保存当前栈顶节点的指针，以便在更新栈顶指针后能正确释放该节点的内存
            // 否则若直接更新stackTop的地址将导致原来栈顶节点的地址丢失，导致内存泄漏
            ListNode *tmp = stackTop;
            stackTop = stackTop->next;
            delete tmp;
            stkSize --;
            return num;
        }

        int top() {
            if (isEmpty())
                throw out_of_range("stack is empty!");
            return stackTop->val;
        }

        vector<int> toVector() {
            ListNode *node = stackTop;
            vector<int> res(size());
            // index倒着循环的目的是：为了保持向量的输出顺序与栈的入栈时顺序保持一致
                // 将最后入栈的元素（链表头）放在向量的最后位置 
            for (int i = res.size() - 1; i >= 0; i--){
                res[i] = node->val;
                node = node->next;
            }
            return res;
        }
};

int main() {
    LinkedListStack *stack = new LinkedListStack();

    stack->push(1);
    stack->push(3);
    stack->push(2);
    stack->push(5);
    stack->push(4);
    cout << "stack = ";
    // 打印结果是[1,3,2,5,4]可以看到向量的存储顺序反映了元素的入栈顺序
    printVector(stack->toVector());

    int top = stack->top();
    cout << "top = " << top << endl;

    top = stack->pop();
    cout << "pop = " << top << ", after pop, stack = ";
    printVector(stack->toVector());

    int size = stack->size();
    cout << "stack size = " << size << endl;

    bool empty = stack->isEmpty();
    cout << "is stack empty? = " << empty << endl;

    delete stack;
    
    return 0;

}
