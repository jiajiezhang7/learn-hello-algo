#include "../utils/common.hpp"

int hashingSearchArray(unordered_map<int, int> map, int target) {
    if (map.find(target) == map.end()) 
        return -1;
    return map[target];
}

ListNode *hashingSearchLinkedList(unordered_map<int, ListNode *> map, int target) {
    if (map.find(target) == map.end())
        return nullptr;
    return map[target];
}

int main() {
    int target = 3;

    vector<int> nums = {1, 5, 3, 2, 4, 7, 5, 9, 10, 8};

    // 构建哈希表
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]] = i;
    }
    
    int index = hashingSearchArray(map, target);
    cout << "target element 3's index = " << index << endl;

    ListNode *head = vecToLinkedList(nums);

    unordered_map<int, ListNode *> map1;
    while (head != nullptr) {
        map1[head->val] = head;
        head = head->next;
    }

    ListNode *node = hashingSearchLinkedList(map1, target);
    cout << "target element 3's node object = " << node << endl;

    return 0;

}
