#include "./array_hash_map.cpp"

class HashMapOpenAddressing {
    private:
        int size;
        int capacity = 4;
        const double loadThres = 2.0 / 3.0;
        const int extendRatio = 2;
        vector<Pair *> buckets;
        Pair *TOMBSTONE = new Pair(-1, "-1");

    public:
        HashMapOpenAddressing() : size(0), buckets(capacity, nullptr) {
        }

        ~HashMapOpenAddressing() {
            for (Pair *pair : buckets) {
                if (pair != nullptr && pair != TOMBSTONE) {
                    delete pair;
                }
            }
            delete TOMBSTONE;
        }

        int hashFunc(int key) {
            return key % capacity;
        }

        double loadFactor() {
            return (double)size / capacity;
        }

        // 线性探测的精髓所在
        int findBucket(int key) {
            int index = hashFunc(key);
            int firstTombstone = -1;
            while (buckets[index] != nullptr) {
                // 其实这里已经找到目标键了
                if (buckets[index]->key == key) {
                    // 如果之前遇到过墓碑，则进行位置优化
                    if (firstTombstone != -1) {
                        buckets[firstTombstone] = buckets[index];
                        buckets[index] = TOMBSTONE;
                        return firstTombstone;
                    }
                    return index;
                }
                if (firstTombstone == -1 && buckets[index] == TOMBSTONE) {
                    firstTombstone = index;
                }

                // 线性探测：移动到下一个位置
                index = (index + 1) % capacity;
            }
            // 当前哈希表中找不到输入的key对应的bucket，那么返回合适的插入位置
                // 优先使用墓碑位置 - 如果查找路径上遇到了墓碑，说明该位置可以被重新使用
            return firstTombstone == -1 ? index : firstTombstone;
        }

        // 查询
        string get(int key) {
            int index = findBucket(key);
            if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
                return buckets[index]->val;
            }
            return "";
        }

        // 添加
        void put(int key, string val) {
            if (loadFactor() > loadThres) {
                extend();
            }
            int index = findBucket(key);

            // 如果找到了键值对，则覆盖val并返回
            if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
                buckets[index]->val = val;
                return;
            }
            buckets[index] = new Pair(key, val);
            size ++;
        }

        void remove(int key){
            int index = findBucket(key);
            if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
                // 释放了它所指向的内存空间，但buckets[index]本身仍然是一个有效的指针
                delete buckets[index];
                // 指针仍然可以被赋值，因为他只是一个存储内存地址的变量，现在将他指向TOMBSTONE对象的内存空间
                buckets[index] = TOMBSTONE;
                size --;
            }
        }

        void extend() {
            vector<Pair *> bucketsTmp = buckets;
            capacity *= extendRatio;
            buckets = vector<Pair *>(capacity, nullptr);
            size = 0;

            for (Pair *pair : bucketsTmp) {
                if (pair != nullptr && pair != TOMBSTONE) {
                    put(pair->key, pair->val);
                    delete pair;
                }
            }
        }

        void print() {
            for (Pair *pair : buckets) {
                if (pair == nullptr) {
                    cout << "nullptr" << endl;
                } else if (pair == TOMBSTONE) {
                    cout <<"TOMBSTONE" << endl;
                } else {
                    cout << pair->key << " -> " << pair->val << endl;
                }
            }
        }
};

