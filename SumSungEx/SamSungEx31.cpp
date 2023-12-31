#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct Edge {
    int st, en, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) : V(V), E(E) {}

    void addEdge(int st, int en, int weight) {
        Edge edge = {st, en, weight};
        edges.push_back(edge);
    }

    void bellmanFord(vector<int>& pi) {
        pi.assign(V, INT_MAX);
        pi[0] = 0;

        for (int i = 1; i <= V - 1; ++i) {
            for (const auto& edge : edges) {
                int u = edge.st;
                int v = edge.en;
                int weight = edge.weight;

                if (pi[u] != INT_MAX && pi[u] + weight < pi[v]) {
                    pi[v] = pi[u] + weight;
                }
            }
        }
    }

    void reweight(vector<int>& pi) {
        for (auto& edge : edges) {
            edge.weight = edge.weight + pi[edge.st] - pi[edge.en];
        }
    }

    void dijkstra(int st) {
        vector<int> dist(V, INT_MAX);
        dist[st] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, st});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& edge : edges) {
                int v = edge.en;
                int weight = edge.weight;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "duong id ngan nhat la: \n";
        for (int i = 0; i < V; ++i) {
            cout << i << " - " << dist[i] << endl;
        }
    }
};

int main() {
    int numVertices, numEdge;
    cin >> numVertices >> numEdge;
    Graph graph(numVertices, numEdge);
    for (int i = 0; i < numEdge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    vector<int> pi;
    graph.bellmanFord(pi);

    graph.reweight(pi);

    graph.dijkstra(0);

    return 0;
}
