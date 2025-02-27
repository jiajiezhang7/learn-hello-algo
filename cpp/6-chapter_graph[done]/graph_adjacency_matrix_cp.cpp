# include "../utils/common.hpp"

// 基于邻接矩阵实现的无向图类
class GraphAdjMat {
    vector<int> vertices;   //顶点列表，元素代表顶点值，索引代表顶点索引

    // 二维向量，外层存储每一行，内层存储每一行的元素
    vector<vector<int>> adjMat;  //邻接矩阵，行、列索引对应顶点索引

    public:
    GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges) {
        for(int val : vertices) {
            addVertex(val);
        }

        for (const vector<int> &edge: edges) {
            addEdge(edge[0], edge[1]);
        }
    }

    int size() const {
        return vertices.size();
    }

    void addVertex(int val) {
        // 在邻接矩阵的尾部添加一行一列，全部填0
        int n = size();
        vertices.push_back(val);
        // 在adjMat末尾添加一个新的元素，这个新的元素是一个vector<int>对象 - n个0的一行
        adjMat.emplace_back(vector<int>(n,0));

        // 遍历邻接矩阵的每一行，并在每一行的尾部添加一个0，相当于在邻接矩阵的尾部添加了一列
        for (vector<int> &row : adjMat) {
            row.push_back(0);
        }
    }

    void removeVertex(int index) {
        if (index >= size()) {
            throw out_of_range("Vertex not exists!");
        }

        // 在顶点列表中移除索引 index 的顶点
        vertices.erase(vertices.begin() + index);

        // vector.erase会自动处理好删除后的向前、向上移动问题，以确保vector内部元素的连续存储
        // 在邻接矩阵中删除索引index的行
        adjMat.erase(adjMat.begin() + index);
        // 在邻接矩阵中删除索引index的列
        for (vector<int> &row : adjMat) {
            row.erase(row.begin() + index);
        }
    }

    void addEdge(int i, int j) {
        if (i < 0 || j < 0 || i >= size() || j>= size() || i == j) {
            throw out_of_range("Vertex not exists!");
        }
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    void removeEdge(int i, int j) {
        if (i < 0 || j < 0 || i >= size() || j >= size() || i ==j) {
            throw out_of_range("Vertex not exists!");
        }
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    void print() {
        cout << "Vertex list = ";
        printVector(vertices);
        cout << "adjacent matrix = " << endl;
        printVectorMatrix(adjMat);
    }
    
};

int main() {
    // 索引与元素的对应：  [0] - 1, [1] - 3, [2] - 2, [3] - 5, [4] - 4  
    vector<int> vertices = {1, 3, 2, 5, 4};
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {2, 3}, {2, 4}, {3, 4}};
    GraphAdjMat graph(vertices, edges);
    cout << "\n after initialization, graph is: " << endl;
    graph.print();

    graph.addEdge(0, 2);
    cout << "\n after add edge 1-2, graph is: " << endl;
    graph.print();

    graph.removeEdge(0, 1);
    cout << "\n after remove edge 1-3, graph is: " << endl;
    graph.print();

    graph.addVertex(6);
    cout << "\n after add vertex 6, graph is: " << endl;
    graph.print();

    graph.removeVertex(1);
    cout <<"\n after remove vertex 3, graph is: " << endl;
    graph.print();

    return 0;
}