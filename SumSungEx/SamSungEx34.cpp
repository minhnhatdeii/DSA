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

    void print(vector<int>& parent, int v) {
        if (parent[v] == -1) {
            cout << v << " ";
            return;
        }
        print(parent, parent[v]);
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

    vector<int> incD, incP, decD, decP;

    graph.dijkstra(0, incD, incP, true);
    graph.dijkstra(0, decD, decP, false);

    cout << "Đường đi ngắn nhất tăng dần từ 0 tới các đỉnh là: " << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "đường đi từ: " << i << ": ";
        graph.print(incP, i);
        cout << "Khoảng cách là : " << incD[i] << endl;
    }

    cout << "Đường đi ngắn nhất giảm dần từ 0 tới các đỉnh là: " << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "đường đi từ: " << i << ": ";
        graph.print(decP, i);
        cout << "Khoảng cách là : " << decD[i] << endl;
    }

    return 0;
}
