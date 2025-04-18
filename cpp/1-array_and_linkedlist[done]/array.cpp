/**
 * File: array.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* 随机访问元素 */
int randomAccess(int *nums, int size) {
    // 在区间 [0, size) 中随机抽取一个数字
    int randomIndex = rand() % size;
    // 获取并返回随机元素
    int randomNum = nums[randomIndex];
    return randomNum;
}

/* 扩展数组长度 */
int *extend(int *nums, int size, int enlarge) {
    // 初始化一个扩展长度后的数组
    int *res = new int[size + enlarge];
    // 将原数组中的所有元素复制到新数组
    for (int i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    // 释放内存
    delete[] nums;
    // 返回扩展后的新数组
    return res;
}

/* 在数组的索引 index 处插入元素 num */
void insert(int *nums, int size, int num, int index) {
    // 把索引 index 以及之后的所有元素向后移动一位
    for (int i = size - 1; i > index; i--) {
        // 由于数组长度是固定的，因此原来数组的最后一位元素将被排挤出数组
        nums[i] = nums[i - 1];
    }
    // 将 num 赋给 index 处的元素
    nums[index] = num;
}

/* 删除索引 index 处的元素 */
void remove(int *nums, int size, int index) {
    // 把索引 index 之后的所有元素向前移动一位
    for (int i = index; i < size - 1; i++) {
        nums[i] = nums[i + 1];
    }
}

/* 遍历数组 */
void traverse(int *nums, int size) {
    int count = 0;
    // 通过索引遍历数组
    for (int i = 0; i < size; i++) {
        count += nums[i];
    }
}

/* 在数组中查找指定元素 */
int find(int *nums, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

/* Driver Code */
int main() {
    /* 初始化数组 */
    int size = 5;
    int *arr = new int[size];
    cout << "数组 arr = ";
    printArray(arr, size);

    int *nums = new int[size]{1, 3, 2, 5, 4};
    cout << "数组 nums = ";
    printArray(nums, size);

    /* 随机访问 */
    int randomNum = randomAccess(nums, size);
    cout << "在 nums 中获取随机元素 " << randomNum << endl;

    /* 长度扩展 */
    int enlarge = 3;
    nums = extend(nums, size, enlarge);
    size += enlarge;
    cout << "将数组长度扩展至 8 ，得到 nums = ";
    printArray(nums, size);

    /* 插入元素 */
    insert(nums, size, 6, 3);
    cout << "在索引 3 处插入数字 6 ，得到 nums = ";
    printArray(nums, size);

    /* 删除元素 */
    remove(nums, size, 2);
    cout << "删除索引 2 处的元素，得到 nums = ";
    printArray(nums, size);

    /* 遍历数组 */
    traverse(nums, size);

    /* 查找元素 */
    int index = find(nums, size, 3);
    cout << "在 nums 中查找元素 3 ，得到索引 = " << index << endl;

    // 释放内存
    delete[] arr;
    delete[] nums;

    return 0;
}
