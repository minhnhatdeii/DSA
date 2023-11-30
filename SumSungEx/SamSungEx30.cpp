#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    void maxPath(int src) {
        stack<int> s;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topoSortUtil(i, visited, s);
            }
        }

        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        while (!s.empty()) {
            int u = s.top();
            s.pop();

            if (dist[u] != INT_MIN) {
                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int w = neighbor.second;

                    if (dist[u] + w > dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        for (int i = 0; i < V; ++i) {
            cout << i << ": ";
            if (dist[i] == INT_MIN) {
                cout << "INF" << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
        cout << endl;
    }

private:
    void topoSortUtil(int v, vector<bool>& visited, stack<int>& s) {
        visited[v] = true;

        for (const auto& neighbor : adj[v]) {
            int u = neighbor.first;
            if (!visited[u]) {
                topoSortUtil(u, visited, s);
            }
        }

        s.push(v);
    }
};

int main() {
    int numVertices, numEdge;
    cin >> numVertices >> numEdge;
    Graph g(numVertices);
    for (int i = 0; i < numEdge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src = 1;
    cout << "đường đi dài nhất từ 1 là: \n";
    g.maxPath(src);

    return 0;
}
