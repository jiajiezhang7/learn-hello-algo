#include "../utils/common.hpp"

void bucketSort(vector<float> &nums) {
    int k = nums.size() / 2;
    vector<vector<float>> buckets(k);

    for (float num : nums) {
        int i = num * k;
        buckets[i].push_back(num);
    }

    for (vector<float> &bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    int i = 0;
    for (vector<float> &bucket : buckets) {
        for (float num : bucket) {
            nums[i++] = num;
        }
    }
}

int main() {
    vector<float> nums = {0.49f, 0.96f, 0.82f, 0.09f, 0.57f, 0.43f, 0.91f, 0.75f, 0.15f, 0.37f};
    bucketSort(nums);
    cout << "after complete bucket sort, nums = ";
    printVector(nums);

    return 0;
}