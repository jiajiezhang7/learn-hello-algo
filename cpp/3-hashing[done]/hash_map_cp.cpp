// 基础的哈希表用法

#include "../utils/common.hpp"

int main() {
    unordered_map<int, string> map;

    map[12836] = "Xiao Ha";
    map[15937] = "Xiao Luo";
    map[16750] = "Xiao Suan";
    map[13276] = "Xiao Fa";
    map[10583] = "Xiao Ya";
    cout << "\n after addition, Hash map is \n Key -> Value" << endl;
    printHashMap(map);

    string name = map[15937];
    
    map.erase(10583);

    cout << "Traverse Key -> Value" << endl;
    // kv 指代的就是键值对的整体
    for (auto kv : map) {
        cout << kv.first << " -> " << kv.second << endl;
    }
    cout << "Traverse Using Iterator" << endl;
    // 迭代器iter其实也指代键值对整体，但是循环方式有所不同
    for (auto iter = map.begin(); iter != map.end(); iter++) {
        cout << iter->first << "->" << iter->second << endl;
    }

    return 0;
}