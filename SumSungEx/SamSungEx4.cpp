
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
const int NumMax = 10000;
vector<int> adj[NumMax];
int color[NumMax];

bool bfs(int u) {
    queue<int> myqueue;
    myqueue.push(u);
    color[u] = 0;
    while (!myqueue.empty()) {
        int v = myqueue.front();
        myqueue.pop();
        for (int next: adj[v]) {
            if (color[next] == -1) {
                color[next] = 1 - color[v];
                myqueue.push(next);
            } else if (color[next] == color[v]) {
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