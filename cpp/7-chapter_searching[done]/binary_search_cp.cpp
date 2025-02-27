#include "../utils/common.hpp"


// 二分查找  --  双闭区间
int binarySearch(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        }else if (nums[m] > target) {
            j = m - 1;
        }else {
            return m;
        }
    }
    return -1;
}

// 二分查找 -- 左闭右开 （时刻想着 右边的j指向的元素是无效的）
int binarySearchLCRO(vector<int> &nums, int target) {
    int i = 0, j = nums.size();
    while (i < j){
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        }else if (nums[m] > target){
            j = m;
        }else {
            return m;
        }
    }
    return -1;
}

// 二分查找 -- 左开右闭
int binarySearchLORC(vector<int> &nums, int target) {
    int i = -1, j = nums.size() - 1;
    while (i < j) {
        // 左边的i指向的元素是无效的，所以要+1使得m偏向右边，避免m指向开区间边界
        int m = i + (j - i + 1) / 2;
        if (nums[m] < target) {
            i = m;
        } else if (nums[m] > target) {
            j = m - 1;
        } else {
            return m;
        }
    }
    return -1;
}

int main() {
    int target = 6;
    vector<int> nums = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};

    int index = binarySearch(nums, target);
    cout << "target element 6's index = " << index << endl;

    index = binarySearchLCRO(nums, target);
    cout << "target element 6's index = " << index << endl;

    index = binarySearchLORC(nums, target);
    cout << "target element 6's index = " << index << endl;

    return 0;
}