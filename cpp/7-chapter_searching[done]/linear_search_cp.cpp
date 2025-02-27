#include "../utils/common.hpp"

int linearSearchArray(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

ListNode *linearSearchLinkedList (ListNode *head, int target) {
    while (head != nullptr) {
        if (head->val == target)
            return head;
        head = head->next;
    }

    return nullptr;
}

int main() {
    int target = 3;

    vector<int> nums = {1, 5, 3, 2, 4, 7, 5, 9, 10, 8};
    int index = linearSearchArray(nums, target);
    cout << "target element 3's index = " << index <<endl;

    ListNode *head = vecToLinkedList(nums);
    ListNode *node = linearSearchLinkedList(head, target);
    cout << "target element 3's node = " << node << endl;

    return 0;
}

