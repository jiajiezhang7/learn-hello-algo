#include "../utils/common.hpp"
#include "./graph_adjacency_list.cpp"

void dfs(GraphAdjList &graph, unordered_set<Vertex *> &visited, vector<Vertex *> &res, Vertex *vet) {
    res.push_back(vet);
    visited.emplace(vet);

    for (Vertex *adjVet : graph.adjList[vet]) {
        if (visited.count(adjVet))
            continue;
        // 递归访问邻接顶点
        dfs(graph, visited, res, adjVet);
    }
}


// 传入一张邻接表，传入一个起始顶点
vector<Vertex *> graphDFS(GraphAdjList &graph, Vertex *startVet) {

    vector<Vertex *> res;
    unordered_set<Vertex *> visited;
    dfs(graph, visited, res, startVet);
    return res;
}


