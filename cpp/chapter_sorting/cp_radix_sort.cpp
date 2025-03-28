// 基数排序

#include "../utils/common.hpp"

// 该函数用于提取数字特定位上的值
int digit(int num, int exp) {
    return (num / exp) % 10;
}

// 对单个数位进行计数排序
void countingSortDigit(vector<int> &nums, int exp) {
    // 创建计数器数组
    vector<int> counter(10 ,0);
    int n = nums.size();

    // 统计每个数位值的出现次数
    for (int i = 0; i < n; i++) {
        int d = digit(nums[i], exp);
        counter[d]++;
    }

    // 计算前缀和
    for (int i = 1; i < 10; i++) {
        counter[i] += counter[i - 1];
    }

    // 从后向前遍历，保持稳定性
    vector<int> res(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        int d = digit(nums[i], exp);
        int j = counter[d] - 1;
        res[j] = nums[i];
        counter[d]--;
    }
    
    // 复制回原数组 
    for (int i = 0; i < n; i++)
        nums[i] = res[i];

}

void radixSort(vector<int> &nums) {
    int m = *max_element(nums.begin(), nums.end());

    for (int exp = 1; exp <= m; exp *= 10){
        countingSortDigit(nums, exp);
    }
}

/* Driver Code */
int main() {
    // 基数排序
    vector<int> nums = {10546151, 35663510, 42865989, 34862445, 81883077,
                        88906420, 72429244, 30524779, 82060337, 63832996};
    radixSort(nums);
    cout << "基数排序完成后 nums = ";
    printVector(nums);

    return 0;
}
