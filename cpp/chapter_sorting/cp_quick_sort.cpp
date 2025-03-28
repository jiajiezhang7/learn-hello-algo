#include "../utils/common.hpp"

class QuickSort {
    private:
        static int partition(vector<int> &nums, int left, int right) {
            int i = left, j = right;
            while (i < j) {
                while (i < j && nums[j] >= nums[left])
                    j --;
                while (i < j && nums[i] <= nums[left])
                    i ++;
                swap(nums[i], nums[j]);
            }
            // 将基准数交换至两子数组的分界线
            swap(nums[i], nums[left]);
            return i;
        }
    public:
        static void quickSort(vector<int> &nums, int left, int right) {
            if (left >= right) return;
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot - 1);
            quickSort(nums, pivot + 1, right);
        }

};

class QucikSortMedian {
    private:
        static int medianThree(vector<int> &nums, int left, int mid, int right) {
            int l = nums[left], m = nums[mid], r = nums[right];
            if ((l <= m && m <=r) || (r <= m && m <= l))
                return mid;
            if ((m <= l && l <= r) || (r <= l && l <= m))
                return left;
            return right;
        }

        static int partition(vector<int> &nums, int left, int right) {
            int med = medianThree(nums, left, (left + right) / 2, right);
            swap(nums[left], nums[med]);
            int i = left, j = right;
            while (i < j) {
                while (i < j && nums[j] >= nums[left])
                    j --;
                while (i < j && nums[i] <= nums[left])
                    i ++;
                swap(nums[i], nums[j]);
            }
            swap(nums[left], nums[j]);
            return i;
        }

    public:
        static void quickSort(vector<int> &nums, int left, int right) {
            if (left >= right)
                return;
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot - 1);
            quickSort(nums, pivot + 1, right);
        }
};

int main() {
    vector<int> nums{2, 4, 1, 0, 3, 5};
    QuickSort::quickSort(nums, 0, nums.size() - 1);
    cout << "after quick sort, nums = ";
    printVector(nums);
}