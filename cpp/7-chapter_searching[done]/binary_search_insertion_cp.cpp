// 二分查找的变体 --- 寻找新元素的插入点

#include "../utils/common.hpp"


// 不存在重复元素
int binarySearchInsertionSimple(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while ( i <= j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        }else if (nums[m] > target) {
            j = m - 1;
        } else {
            return m;
        }
    }
    // 如果未找到跟target相等的元素，则返回的i是否意味着是target的元素的索引
    return i;
}

int binarySearchInsertion(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        }else if (nums[m] > target) {
            j = m - 1;
        }else {
            j = m - 1;   // 继续缩小边界，因为首个小于target的元素会出现在 [i, m-1] 中
        }
    }
    return i;  // i 将是首个大于 target 的元素
}

int main() {
    vector<int> nums = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};
    cout << "\n array nums = ";
    printVector(nums);
    for (int target : {6, 9}) {
        int index = binarySearchInsertionSimple(nums, target);
        cout << "element " << target << "'s insertion index = " << index << endl;
    }

    nums = {1, 3, 6, 6, 6, 6, 6, 10, 12, 15};
    cout << "\narray nums = ";
    printVector(nums);
    for (int target : {2, 6, 20}) {
        int index = binarySearchInsertion(nums, target);
        cout << "element " << target << "'s insertion index = " << index << endl;
    }
    return 0;
}



