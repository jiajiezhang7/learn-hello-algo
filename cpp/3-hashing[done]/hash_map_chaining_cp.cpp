// 尝试使用“链式地址”解决“哈希冲突”

#include "./array_hash_map.cpp"

class HashMapChaining {
    private:
        int size;
        int capacity;
        double loadThres;
        int extendRatio;
        vector<vector<Pair *>> buckets;
    
    public:
        HashMapChaining() : size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2) {
            buckets.resize(capacity);
        }

        ~HashMapChaining() {
            // 每个bucket会存储的是一个链表
            for (auto &bucket : buckets) {
                for (Pair *pair : bucket) {
                    delete pair;
                }
            }
        }

        int hashFunc(int key) {
            return key % capacity;
        }
        double loadFactor() {
            return (double)size / (double)capacity;
        }

        string get(int key) {
            int index = hashFunc(key);
            // 找到对应的桶，遍历桶的链表
            for (Pair *pair : buckets[index]) {
                if (pair->key == key) {
                    return pair->val;
                }
            }
            return "";
        }

        void put(int key, string val) {
            if (loadFactor() > loadThres) {
                extend();
            }
            int index = hashFunc(key);
            for (Pair *pair : buckets[index]) {
                if (pair->key == key) {
                    pair->val = val;
                    return;
                }
            }
            buckets[index].push_back(new Pair(key, val));
            size++;
        }

        void remove(int key) {
            int index = hashFunc(key);
            auto &bucket = buckets[index];
            for (int i = 0; i < bucket.size(); i++) {
                if (bucket[i]->key == key) {
                    // 暂存指针
                    Pair *tmp = bucket[i];
                    // erase方法会从vector中移除指定位置的元素，但是不会自动释放动态分配的内存
                    bucket.erase(bucket.begin() + i);
                    // 释放指针指向的内存
                    delete tmp;
                    size--;
                    return;
                }
            }
        }

        void extend() {
            // 暂存原来的哈希表
            vector<vector<Pair *>> bucketsTmp = buckets;
            capacity *= extendRatio;
            buckets.clear();
            buckets.resize(capacity);
            size = 0;
            for (auto &bucket : bucketsTmp) {
                for (Pair *pair : bucket) {
                    // put默认会把pair放进HashMapChaining的buckets里面
                    put(pair->key, pair->val);
                    delete pair;
                }
            }
        }

        void print() {
            for (auto &bucket : buckets) {
                cout << "[";
                for (Pair *pair : bucket) {
                    cout << pair->key << " -> " << pair->val << ", ";
                }
                cout << "]\n";
            }
        }
};

int main() {
    HashMapChaining map = HashMapChaining();

    map.put(12836, "小哈");
    map.put(15937, "小啰");
    map.put(16750, "小算");
    map.put(13276, "小法");
    map.put(10583, "小鸭");
    cout << "\n添加完成后，哈希表为\nKey -> Value" << endl;
    map.print();
    
    /* 查询操作 */
    // 向哈希表中输入键 key ，得到值 value
    string name = map.get(13276);
    cout << "\n输入学号 13276 ，查询到姓名 " << name << endl;

    /* 删除操作 */
    // 在哈希表中删除键值对 (key, value)
    map.remove(12836);
    cout << "\n删除 12836 后，哈希表为\nKey -> Value" << endl;
    map.print();

    return 0;
}