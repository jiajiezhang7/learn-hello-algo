#include "../utils/common.hpp"

void selectionSort(vector<int> &nums){
    int n = nums.size();
    // 外层循环中，最后一个元素不需要比较
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        // 内层循环负责寻找：有没有比当前元素更小的
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[k])
                k = j;
        }
        swap(nums[i], nums[k]);
    }
}

int main() {
    vector<int> nums = {4, 1, 3, 1, 5, 2};
    selectionSort(nums);

    cout << "after selection sort, nums = ";
    printVector(nums);

    return 0;
}