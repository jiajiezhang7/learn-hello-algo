// 天真地设计几个哈希函数

#include "../utils/common.hpp"

int addHash(string key) {
    long long hash = 0;
    const int MODULUS = 1000000007;
    // 遍历字符串中的每个字符，将其ASCII码值累加到一个变量中
    for (unsigned char c : key) {
        hash = (hash + (int)c) % MODULUS;
    }
    return (int)hash;
}

int mulHash(string key) {
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key) {
        hash = (31 * hash + (int)c) % MODULUS;
    }
    return (int)hash;
}

int xorHash(string key) {
    int hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key) {
        hash ^= (int)c;
    }
    return hash & MODULUS;
}

int rotHash(string key) {
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key) {
        // 循环移位 + 异或操作
        hash = ((hash << 4) ^ (hash >> 28) ^ (int)c % MODULUS);
    }
    return (int)hash;
}

