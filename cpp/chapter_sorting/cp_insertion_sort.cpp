#include "../utils/common.hpp"
// 插入排序：通过逐步将未排序元素插入到已排序区间的正确位置，最终实现整个数组的排序
void insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        // base是待排序的元素，要把它插入到正确的位置
        int base = nums[i], j = i - 1;
        while (j >= 0 && nums[j] > base) {
            // 把 nums[j] 往右移动，因为要给base腾出位置
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}

int main() {
    vector<int> nums = {4, 1, 3, 1, 5 ,2};
    insertionSort(nums);
    cout << "after insertion sort, nums = ";
    printVector(nums);

    return 0;
}

