#include "../utils/common.hpp"

// 题目： 给定一个长度为n的有序数组 nums，其中可能包含重复元素，
    // 请返回数组中最左一个元素 target 的索引，若不包含该元素则返回-1

int binarySearchInsertion(const vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        } else {
            // 隐式处理 -- 在 nums[m] > target || nums[m] == target时都如此处理
            j = m - 1;
        }
    }
    return i;
}

int binarySearchLeftEdge(vector<int> &nums, int target) {
    
    int i = binarySearchInsertion(nums, target);

    // i == nums.size() 意味着 target大于数组中的所有元素，并且为了防止后者条件判断导致数组越界
        // 所以显式写明条件
    if (i == nums.size() || nums[i] != target) {
        return -1;
    }
    return i;
}

// 以下函数的巧妙的点：
// 通过传入 target + 1，binarySearchInsertion 函数会返回第一个大于 target 的元素的位置 i。
// 由于 i 是第一个大于 target 的元素的位置，i - 1 自然就是 target 的右边界。
int binarySearchRightEdge(vector<int> &nums, int target) {

    int i = binarySearchInsertion(nums, target + 1);

    int j = i -1;

    if (j == -1 || nums[j] != target) {
        return -1;
    }
    return j;
}


int main() {
    vector<int> nums = {1, 3, 6, 6, 6, 6, 6, 10, 12, 15};
    printVector(nums);

    for (int target : {6, 7}) {
        int index = binarySearchLeftEdge(nums, target);
        cout << "Last left element: " << target << "'s index = " << index << endl;
        index = binarySearchRightEdge(nums, target);
        cout << "Last right element: " << target << "'s index = " << index << endl;
    }
    return 0;
}
