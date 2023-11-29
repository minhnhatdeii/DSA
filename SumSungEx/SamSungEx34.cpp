#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

typedef pair<int, int> pii;

class Graph {
public:
    int V; 
    vector<vector<Edge>> adj; 

    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); 
    }

    void dijkstra(int start, vector<int>& dist, vector<int>& parent, bool increasing) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist.assign(V, INF);
        parent.assign(V, -1);

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (const Edge& edge : adj[u]) {
                int v = edge.to;
                int w = edge.weight;

                if (increasing && w < dist[v]) {
                    dist[v] = w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                } else if (!increasing && w > dist[v]) {
                    dist[v] = w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    void printPath(vector<int>& parent, int v) {
        if (parent[v] == -1) {
            cout << v << " ";
            return;
        }
        printPath(parent, parent[v]);
        cout << v << " ";
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

    vector<int> increasingDist, increasingParent, decreasingDist, decreasingParent;

    graph.dijkstra(0, increasingDist, increasingParent, true);
    graph.dijkstra(0, decreasingDist, decreasingParent, false);

    cout << "Đường đi ngắn nhất tăng dần từ 0 tới các đỉnh là: " << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "đường đi từ: " << i << ": ";
        graph.printPath(increasingParent, i);
        cout << "Khoảng cách là : " << increasingDist[i] << endl;
    }

    cout << "Đường đi ngắn nhất giảm dần từ 0 tới các đỉnh là: " << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "đường đi từ: " << i << ": ";
        graph.printPath(decreasingParent, i);
        cout << "Khoảng cách là : " << decreasingDist[i] << endl;
    }

    return 0;
}
