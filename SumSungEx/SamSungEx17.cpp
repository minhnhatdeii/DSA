#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V;
    int E;
    vector<vector<int>> edges;

public:
    Graph(int v, int e) : V(v), E(e) {
        edges.resize(E, vector<int>(3, 0));
    }

    void addEdge(int edgeIndex, int u, int v, int w) {
        edges[edgeIndex][0] = u;
        edges[edgeIndex][1] = v;
        edges[edgeIndex][2] = w;
    }

    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    vector<vector<int>> vyssotsky() {
        vector<vector<int>> result;
        int i = 0, e = 0;

        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; ++i)
            parent[i] = i;

        while (e < V - 1 && i < E) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            ++i;

            int x = find(parent, u);
            int y = find(parent, v);

            if (x != y) {
                ++e;
                result.push_back({u, v, w});
                Union(parent, rank, x, y);
            }
        }

        return result;
    }
};

int main() {

    int numVertices, numEdge;
    cin >> numVertices >> numEdge;

    Graph graph(numVertices, numEdge);

    for (int i = 0; i < numEdge; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(i, u, v, w);
    }
    vector<vector<int>> mstResult = graph.vyssotsky();

    for (const vector<int>& edge : mstResult) {
        cout << edge[0] << edge[1] << edge[2] << endl;
    }

    return 0;
}