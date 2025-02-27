#include "../utils/common.hpp"

int main() {
    vector<int> nums = {1, 3, 2, 5, 4};

    int num = nums[1];

    nums[1] = 0;

    nums.clear();

    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);

    // 在索引3处插入数字6
    nums.insert(nums.begin() + 3, 6);

    // 删除索引3处的元素
    nums.erase(nums.begin() + 3);

    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        count += nums[i];
    }

    count = 0;
    for (int x : nums) {
        count += x;
    }

    vector<int> nums1 = {6, 8, 7, 10, 9};
    nums.insert(nums.end(), nums1.begin(), nums1.end());
    
    sort(nums.begin(), nums.end());
    
    return 0;
}