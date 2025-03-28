#include "../utils/common.hpp"

// 向下堆化的目的：当一个节点的值可能小于其子节点时，通过交换操作，使其恢复堆的性质
void siftDown(vector<int> &nums, int n, int i) {
    while (true) {
        // 左子节点索引
        int l = 2 * i + 1;
        // 右子节点索引
        int r = 2 * i + 2;
        // 假设当前节点最大
        int ma = i;
        // 如果左子节点存在且大于当前最大值，则更新最大值索引
        if (l < n && nums[l] > nums[ma])
            ma = l;
        // 同上理
        if (r < n && nums[r] > nums[ma])
            ma = r;
        // 如果当前节点已经是最大的，则堆性质满足，退出循环
        if (ma == i) {
            break;
        }

        // 否则，交换当前节点与最大子节点
        swap(nums[i], nums[ma]);

        // 堆化是一个“向下传播”的修复过程，当一个较小的值从上层被交换到下层后
            // 它可能需要继续下沉，直到找到合适的位置
        i = ma;
    }
}

void heapSort(vector<int> &nums) {
    // 第一阶段：建堆
        // 从后向前处理每个非叶子节点,确保每个子树都是一个大顶堆
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
        siftDown(nums, nums.size(), i);
    }
    // 第二阶段：排序 (每次循环都会将i - 堆的大小减1)
    for (int i = nums.size() - 1; i > 0; --i) {
        // 将堆顶元素(当前最大值)与堆的最后一个元素交换
        swap(nums[0], nums[i]);
        // 对新的堆顶元素执行向下堆化，恢复堆的性质
        siftDown(nums, i , 0);
    }
}

int main() {
    vector<int> nums = {4, 1, 3, 1, 5, 2};
    heapSort(nums);
    cout << "after heap sort, nums = ";
    printVector(nums);

    return 0;
}