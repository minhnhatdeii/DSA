#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

class Graph {
private:
	vector<vector<pair<int,int>>> adj;
	int V;
public:
	Graph() {}
	Graph(int n) {
		V = n;
		while (n--) {
			vector<pair<int,int>> tmp;
			adj.push_back(tmp);
		}
 	}

 	void addEdge(int u, int v, int w) {
 		adj[u].push_back({v,w});
 		adj[v].push_back({u,w});
 	}

 	void dijkstra(int start) {
 		vector<int> dist(V, INT_MAX);
 		vector<int> parent(V, INT_MIN);
 		dist[start] = 0;
 		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

 		pq.push({0, start});
 		while (!pq.empty()) {
 			pair<int, int> cur = pq.top();
 			pq.pop();
 			int u = cur.second;
 			for (auto next : adj[u]) {
 				int v = next.first;
 				int uv = next.second;
 				if (dist[v] > (dist[u]+uv)) {
 					dist[v] = dist[u] + uv;
 					parent[v] = u;
 					pq.push({dist[v], v});
 				} 
 			}
 		}

 		for (int i = 0; i < V; i++) {
            cout << start << i  << dist[i];
            stack<int> s;
            int j = i;
            while (j != start) {
            	s.push(j);
            	j = parent[j];
            }
            s.push(j);
            while (!s.empty()) {
            	cout << s.top() << " ";
            	s.pop();
            }
            cout << endl;
        }
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
    int start = 0;
    g.dijkstra(start);

}