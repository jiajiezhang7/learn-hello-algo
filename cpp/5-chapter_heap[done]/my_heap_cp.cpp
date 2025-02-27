#include "../utils/common.hpp"

// 由于堆是一种特别的时完美二叉树，因此底层采用数组来实现是绝佳的实践
// 这里实现大顶堆，顶部根节点值是最大的
class MaxHeap {
    private:
        vector<int> maxHeap;

        int left(int i) {
            return 2 * i + 1;
        }

        int right(int i) {
            return 2 * i + 2;
        }

        int parent(int i) {
            return (i - 1) / 2;
        }

        // 由下往上heapify - 对于大顶堆 - 如果子节点 > 父节点，则两者交换位置
        void siftUp(int i) {
            while (true) {
                int p = parent(i);

                if (p < 0 || maxHeap[i] <= maxHeap[p])
                    break;
                swap(maxHeap[i], maxHeap[p]);
                i = p;
            }
        }

        // 由上往下heapify - 对于大顶堆 - 如果父节点 < 子节点，则两者交换位置
        void siftDown(int i) {
            while (true) {
                int l = left(i), r = right(i), ma = i;
                if (l < size() && maxHeap[l] > maxHeap[ma])
                    ma = l;
                if (r < size() && maxHeap[r] > maxHeap[ma])
                    ma = r;
                if (ma == i)
                    break;
                swap(maxHeap[i], maxHeap[ma]);
                i = ma;
            }
        }

    public:

        MaxHeap(vector<int> nums) {
            maxHeap = nums;

            // 对于最底层的子树，进行“从顶至底”堆化，这样可保证每往上一层时，其下一层都是满足堆条件的
            for (int i = parent(size() - 1); i >= 0; i--) {
                siftDown(i);
            }
        }
        
        int size() {
            return maxHeap.size();
        }

        bool isEmpty() {
            return size() == 0;
        }

        int peek() {
            return maxHeap[0];
        }

        void push(int val) {
            maxHeap.push_back(val);
            siftUp(size() - 1);
        }

        void pop() {
            if (isEmpty()){
                throw out_of_range("heap is empty!!!");
            }

            swap(maxHeap[0], maxHeap[size() - 1]);

            maxHeap.pop_back();

            siftDown(0);
        }

        void print() {
            cout << "Heap represented by array: " << endl;
            printVector(maxHeap);
            cout << "Heap represented by Tree-alike: " << endl;
            TreeNode *root = vectorToTree(maxHeap);
            printTree(root);
            freeMemoryTree(root);
        }
};

int main() {
    vector<int> vec{9, 8, 6, 6, 7, 5, 2, 1, 4, 3, 6, 2};
    MaxHeap maxHeap(vec);
    cout << "\n after input list and construct heap: " << endl;
    maxHeap.print();
}