#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[1000];
bool is_edge_connected = true;
void DFS(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<int> adj[]) {
    static int time = 0;
    int children = 0;

    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            DFS(v, visited, disc, low, parent, adj);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                cout << u << " - " << v << endl;
                is_edge_connected = false;
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void CheckEdgeConnected(int vertices) {
    vector<bool> visited(vertices, false);
    vector<int> disc(vertices, 0);
    vector<int> low(vertices, 0);
    vector<int> parent(vertices, -1);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(i, visited, disc, low, parent, adj);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    CheckEdgeConnected(n);
    if (is_edge_connected) {
        cout << "đồ thị có liên thông cạnh!" << endl;
    } else {
        cout << "đồ thị không liên thông cạnh!" << endl;
    }

    return 0;
}


