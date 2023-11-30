#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

class Graph {
private:
    int V;
    vector<vector<int>> distance;

public:
    Graph(int vertices) : V(vertices) {
        distance.resize(V, vector<int>(V, INF));
    }

    void addEdge(int u, int v, int w) {
        distance[u][v] = distance[v][u] = w;
    }

    void process() {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (distance[i][k] != INF && distance[k][j] != INF &&
                        distance[i][k] + distance[k][j] < distance[i][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
    }

    int getMinDis(int u, int v) {
        return distance[u][v];
    }
};

int main() {
    int numVertices, numEdge;
    cin >> numVertices >> numEdge;
    Graph graph(numVertices);
    for (int i = 0; i < numEdge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    graph.process();

    int u = 0, v = 2;
    int shortestDistance = graph.getMinDis(u, v);

    if (shortestDistance != INF) {
        cout << "khoảng cách ngắn nhất giứa" << u << " và " << v << " là: " << shortestDistance << endl;
    } else {
        cout << "không tìm thấy đường đi giữa" << u << " và " << v << endl;
    }

    return 0;
}
