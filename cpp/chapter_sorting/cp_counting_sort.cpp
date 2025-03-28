#include "../utils/common.hpp"

void countingSortNaive(vector<int> &nums) {
    int m = 0;
    for (int num : nums) {
        m = max(m ,num);
    }

    vector<int> counter(m + 1, 0);
    for (int num : nums) {
        counter[num] ++;
    }

    int i = 0;
    for (int num = 0; num < m + 1; num++) {
        for (int j = 0; j < counter[num]; j++, i++) {
            nums[i] = num;
        }
    }
}

void countingSort(vector<int> &nums) {
    int m = 0;
    for (int num : nums) {
        m = max(m, num);
    }

    vector<int> counter(m + 1, 0);
    for (int num : nums) {
        counter[num]++;
    }

    // 求counter的前缀和
    for (int i = 0; i < m; i++) {
        counter[i + 1] += counter[i];
    }

    int n = nums.size();
    vector<int> res(n);
    // 从后往前遍历原数组
    for (int i = n - 1; i >= 0; i--) {
        // 当前处理的元素
        int num = nums[i];
        // 放置到结果数组的正确位置
        res[counter[num] - 1] = num;
        // 更新位置，为同样的数字准备下一个位置
        counter[num]--;
    }
    nums = res;
}


int main() {
    vector<int> nums = {1, 0, 1, 2, 0, 4, 0, 2, 2, 4};
    countingSortNaive(nums);

    cout << "after naive counting sort, nums = ";
    printVector(nums);
}