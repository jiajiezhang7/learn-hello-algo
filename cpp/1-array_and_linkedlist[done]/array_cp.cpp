#include "../utils/common.hpp"

int randomAccess(int *nums, int size) {
    int randomIndex = rand() % size;

    int randomNum = nums[randomIndex];
    return randomNum;
}

int *extend(int *nums, int size, int enlarge) {

    int *res = new int[size + enlarge];
    for (int i = 0; i < size; i++){
        res[i] = nums[i];
    }
    delete []nums;
    return res;
}

void insert(int *nums, int size, int num, int index) {
    for (int i = size - 1; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    nums[index] = num;
}

void remove(int *nums, int size, int index) {
    for (int i = index; i < size - 1; i++){
        nums[i] = nums[i + 1];
    }
}

void traverse(int *nums, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        count += nums[i];
    }
}


int find(int *nums, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}
