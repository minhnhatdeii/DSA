#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int v, int e) : V(v), E(e) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    void primMST() {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        key[0] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = minKey(key, inMST);
            inMST[u] = true;

            for (const auto& edge : edges) {
                if (edge.src == u && !inMST[edge.dest] && edge.weight < key[edge.dest]) {
                    parent[edge.dest] = u;
                    key[edge.dest] = edge.weight;
                }
            }
        }

        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << " (" << key[i] << ")" << endl;
        }
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V, -1); // Dùng để kiểm tra chu trình


        for (Edge edge : edges) {
            int rootSrc = find(parent, edge.src);
            int rootDest = find(parent, edge.dest);

            if (rootSrc != rootDest) {
                cout << edge.src << " - " << edge.dest << " (" << edge.weight << ")" << endl;
                unionSets(parent, rootSrc, rootDest);
            }
        }
    }

private:
    int find(vector<int>& parent, int u) {
        if (parent[u] == -1)
            return u;
        return find(parent, parent[u]);
    }

    void unionSets(vector<int>& parent, int u, int v) {
        int rootU = find(parent, u);
        int rootV = find(parent, v);
        parent[rootU] = rootV;
    }

    int minKey(const vector<int>& key, const vector<bool>& inMST) {
        int min = INT_MAX, minIndex = -1;

        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }
};

int main() {

    int numVertices, numEdge;
    cin >> numVertices >> numEdge;
    Graph g(numVertices, numEdge);

    for (int i = 0; i < numEdge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.primMST();

    g.kruskalMST();

    return 0;
}
