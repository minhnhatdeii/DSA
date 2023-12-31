#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct level {
    int parent, rank;
};

class Graph {
private:
    int V, E;
    vector<Edge> edges;

public:
    Graph(int vertices, int edges);
    void addEdge(int src, int dest, int weight);
    int find(level levels[], int i);
    void Union(level levels[], int x, int y);
    void boruvkaMST();
};

Graph::Graph(int vertices, int edges) {
    V = vertices;
    E = edges;
}

void Graph::addEdge(int src, int dest, int weight) {
    Edge edge = {src, dest, weight};
    edges.push_back(edge);
}

int Graph::find(level levels[], int i) {
    if (levels[i].parent != i)
        levels[i].parent = find(levels, levels[i].parent);

    return levels[i].parent;
}

void Graph::Union(level levels[], int x, int y) {
    int xroot = find(levels, x);
    int yroot = find(levels, y);

    if (levels[xroot].rank < levels[yroot].rank)
        levels[xroot].parent = yroot;
    else if (levels[xroot].rank > levels[yroot].rank)
        levels[yroot].parent = xroot;
    else {
        levels[yroot].parent = xroot;
        levels[xroot].rank++;
    }
}

void Graph::boruvka() {
    level* levels = new level[V];
    vector<Edge> result;

    for (int v = 0; v < V; v++) {
        levels[v].parent = v;
        levels[v].rank = 0;
    }

    int numTrees = V;

    while (numTrees > 1) {
        vector<int> cheapest(V, -1);

        for (int i = 0; i < E; i++) {
            int set1 = find(levels, edges[i].src);
            int set2 = find(levels, edges[i].dest);

            if (set1 != set2) {
                if (cheapest[set1] == -1 || edges[cheapest[set1]].weight > edges[i].weight)
                    cheapest[set1] = i;

                if (cheapest[set2] == -1 || edges[cheapest[set2]].weight > edges[i].weight)
                    cheapest[set2] = i;
            }
        }

        for (int i = 0; i < V; i++) {
            if (cheapest[i] != -1) {
                int set1 = find(levels, edges[cheapest[i]].src);
                int set2 = find(levels, edges[cheapest[i]].dest);

                if (set1 != set2) {
                    result.push_back(edges[cheapest[i]]);
                    Union(levels, set1, set2);
                    numTrees--;
                }
            }
        }
    }

    for (Edge edge : result) {
        cout << edge.src << edge.dest << edge.weight << endl;
    }

    delete[] levels;
}

int main() {
    int numVertices, numEdge;
    cin >> numVertices >> numEdge;

    Graph graph(numVertices, numEdge);

    for (int i = 0; i < numEdge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.boruvka();

    return 0;
}

/* CHỨNG MINH VIỆC TÌM CÂY KHUNG NHỎ NHẤT
 * Trong mỗi bước của thuật toán, chúng ta chọn cạnh có trọng số nhỏ nhất kết nối hai
 * thành phần liên thông khác nhau. Điều này đảm bảo rằng cây bao trùm min tìm được
 * sẽ bao trùm tất cả các đỉnh.Khi thêm một cạnh vào cây bao trùm, chúng ta gộp hai
 * thành phần liên thông lại với nhau. Điều này đảm bảo rằng cây bao trùm được xây
 * dựng sẽ liên thông.Chúng ta luôn chọn cạnh có trọng số nhỏ nhất kết nối hai thành
 * phần liên thông khác nhau. Do đó, cây bao trùm min tìm được chứa cạnh nhỏ nhất kết
 * nối mỗi cặp thành phần liên thông.
 */

/*
 * ĐỘ PHỨC TẠP
 * Độ phức tạp của thuật toán Boruvka phụ thuộc chủ yếu vào việc sắp xếp các cạnh
 * theo trọng số. Giả sử có V đỉnh và E cạnh thuật toán thực hiện tối đa V vòng lặp
 *  (mỗi vòng lặp giảm số thành phần liên thông đi ít nhất một).
 *  Độ phức tạp của sắp xếp cạnh là O(ElogE) (Với E là số cạnh).
 *  Trong mỗi vòng lặp, chúng ta cần tìm thành phần liên thông cho mỗi đỉnh. Trong trường
 *  hợp tốt nhất, mỗi đỉnh chỉ thuộc vào một thành phần liên thông và tìm nó có độ phức tạp
 * O(1). Trong trường hợp tồi nhất, mỗi đỉnh thuộc vào một thành phần liên thông riêng biệt
 * và tìm thành phần liên thông có độ phức tạp O(V).Do đó, độ phức tạp tổng cộng của
 * thuật toán Boruvka là O(ElogE + V^2)
 */
