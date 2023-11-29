//Kiem tra do thi 2 mau.

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
const int NumMax = 10000;
vector<int> adj[NumMax];
int color[NumMax];

bool bfs(int u) {
    queue<int> q;
    q.push(u);
    color[u] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int neighbor: adj[v]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[v];
                q.push(neighbor);
            } else if (color[neighbor] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int numVertices, numEdge;
    cin >> numVertices >> numEdge;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(color, -1, sizeof(color));
    bool check = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (!bfs(i)) {
                check = false;
                break;
            }
        }
    }
    if (check) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}