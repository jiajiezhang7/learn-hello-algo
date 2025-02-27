#include "../utils/common.hpp"

class GraphAdjList {
    public:
        // 邻接表 - 无序哈希表实现
        // Key: Vertex* 顶点指针 --- Value: vector<Vertex*>与该顶点相邻的所有顶点
        unordered_map<Vertex *, vector<Vertex *>> adjList;

        // 构造函数
        GraphAdjList(const vector<vector<Vertex *>> &edges) {
            for (const vector<Vertex *> &edge :edges) {
                // 对于每一条边，它都包含两个顶点
                addVertex(edge[0]);
                addVertex(edge[1]);
                // 将刚才的这两个顶点连起来
                addEdge(edge[0], edge[1]);
            }
        }

        int size() {
            return adjList.size();
        }

        void addEdge(Vertex *vet1, Vertex *vet2) {
            if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2) {
                throw invalid_argument("Vertex not exists!");
            }
            adjList[vet1].push_back(vet2);
            adjList[vet2].push_back(vet1);
        }

        // 根据新键vet，创建一个新的键值对（值列表最初是空的）
        void addVertex(Vertex *vet) {
            if (adjList.count(vet))
                return;
            adjList[vet] = vector<Vertex *>();
        }

        // 在 vector中删除指定节点
        void remove(vector<Vertex *> &vec, Vertex *vet) {
            for (int i = 0; i < vec.size(); i++) {
                if (vec[i] == vet) {
                    vec.erase(vec.begin() + i);
                    break;
                }
            }
        }

        void removeEdge(Vertex *vet1, Vertex *vet2) {
            if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
                throw invalid_argument("Vertex not exists!");
            // 从 vet1 的邻接列表中移除 vet2
            remove(adjList[vet1], vet2);
            // 从 vet2 的邻接列表中移除 vet1
            remove(adjList[vet2], vet1);
        }

        void removeVertex(Vertex *vet) {
            if (!adjList.count(vet))
                throw invalid_argument("Vertex not exists!");

            // 删除顶点 vet 对应的键值对
            adjList.erase(vet);

            // 遍历每一个还存在的键值对，从每个顶点的邻接列表中移除刚刚删除的vet
            for (pair<Vertex* const, vector<Vertex*>>& adj : adjList) {
                remove(adj.second, vet);
            }
        }

        void print() {
            cout << "adjList = " << endl;
            // 遍历adjList中的每一个键值对
            for (auto &adj : adjList) {
                // 获取顶点指针
                const auto &key = adj.first;
                // 获取对应的邻接列表
                const auto &vec = adj.second;
                cout << key->val << ": ";
                printVector(vetsToVals(vec));
            }
        }

};