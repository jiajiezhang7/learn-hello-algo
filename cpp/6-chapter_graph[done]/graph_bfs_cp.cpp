#include "../utils/common.hpp"
#include "./graph_adjacency_list_cp.cpp"


// 广度优先搜索，先进先出思想 -- 队列实现
vector<Vertex *> graphBFS(GraphAdjList &graph, Vertex *startVet) {
    
    // 顶点遍历后的输出序列（结果不唯一）
    vector<Vertex *> res;
    // 哈希集合，用于记录已被访问过的顶点
    unordered_set<Vertex *> visited = {startVet};
    // 队列用于实现 BFS
    queue<Vertex *> que;
    // 顶点入队
    que.push(startVet);

    // 以顶点 vet 为起点，循环直至访问完所有顶点
    while (!que.empty()) {
        Vertex *vet = que.front();
        // 队首顶点出队
        que.pop();
        // 记录访问顶点（作为输出序列）
        res.push_back(vet);
        // 遍历该顶点的所有邻接顶点 --- 也即遍历这个顶点的邻接表中的所有元素
        for (auto adjVet : graph.adjList[vet]) {
            // 跳过已被访问的顶点
            if (visited.count(adjVet))
                continue;
            // 只入队未访问的顶点
            que.push(adjVet);
            // 标记该顶点已被访问
            visited.emplace(adjVet);
        }
    }
    // 返回顶点遍历序列
    return res;
}
