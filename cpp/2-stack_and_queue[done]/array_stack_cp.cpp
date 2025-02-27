#include "../utils/common.hpp"

// 用数组实现栈的特性（内部是数组，对外表现为栈，自定义实现栈的method）
class ArrayStack {
    private:
        vector<int> stack;

    public:
        int size() {
            return stack.size();
        }

        bool isEmpty(){
            return stack.size() == 0;
        }

        void push(int num) {
            stack.push_back(num);
        }

        int pop() {
            int num = top();
            stack.pop_back();
            return num;
        }

        int top() {
            if (isEmpty())
                throw out_of_range("the stack is empty!");
            return stack.back();
        }

        vector<int> toVector() {
            return stack;
        }
};

int main() {
    ArrayStack *stack = new ArrayStack();

    stack->push(1);
    stack->push(3);
    stack->push(2);
    stack->push(5);
    stack->push(4);
    cout << "stack = ";
    printVector(stack->toVector());

    int top = stack->top();
    cout << "top = " << top << endl;

    top = stack->pop();
    cout << "pop = " << top << "after pop, stack = ";
    printVector(stack->toVector());

    int size = stack->size();
    cout << "size = " << size << endl;

    bool empty = stack->isEmpty();
    cout << "is stack empty? = " << empty << endl;

    delete stack;

    return 0;
}
