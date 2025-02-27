#include "../utils/common.hpp"

// 题目：给定一个数组 nums 和一个目标值 target，找出数组中是否有两数之和=target，
    // 若有，则返回这两个数的索引

// 暴力枚举
vector<int> twoSumBruteForce(vector<int> &nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j ++) {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}

// 辅助哈希表方法 -- 以空间换时间
vector<int> twoSumHashTable(vector<int> &nums, int target) {
    int size = nums.size();
    unordered_map<int, int> dic;
    for (int i = 0; i < size; i++) {
        if (dic.find(target - nums[i]) != dic.end()) {
            return {dic[target - nums[i]], i};
        }
        dic.emplace(nums[i], i);
    }
    
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;

    vector<int> res = twoSumBruteForce(nums, target);
    printVector(res);

    res = twoSumHashTable(nums, target);
    printVector(res);

    return 0;
}

