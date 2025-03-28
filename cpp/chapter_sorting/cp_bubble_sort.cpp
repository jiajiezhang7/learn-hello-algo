#include "../utils/common.hpp"

void bubbleSort(vector<int> &nums) {
    // 外层：未排序区间为:[0, i]
    for (int i = nums.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
             // 把更大的元素逐渐交换到区间 [0, i]最右侧
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void bubbleSortWithFlag(vector<int> &nums) {
    for (int i = nums.size() - 1; i > 0; i--) {
        bool flag = false;
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
    if (!flag) break;
    }
}

int main() {
    vector<int> nums = {4, 1, 3, 1, 5, 2};
    bubbleSort(nums);
    cout << "after bubble sort, nums = ";
    printVector(nums);

    vector<int> nums1 = {4, 1, 3, 1, 5, 2};
    bubbleSortWithFlag(nums1);
    cout << "after bubble sort with flag, nums = ";
    printVector(nums1);

    return 0;
}