#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void topoSort(vector<vector<int>> &graph, vector<int> &order, vector<bool> &visited, int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            topoSort(graph, order, visited, neighbor);
        }
    }
    order.push_back(node);
}

bool unique(vector<vector<int>> &graph) {
    vector<int> myVec;
    vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            topoSort(graph, myVec, visited, i);
        }
    }
    reverse(myVec.begin(), myVec.end());
    for (int i = 0; i < myVec.size() - 1; i++) {
        int u = myVec[i];
        int v = myVec[i + 1];
        bool found = false;
        for (int neighbor : graph[u]) {
            if (neighbor == v) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    bool result = unique(graph);
    if (result) {
        cout << "đồ thị có một thứ tự topo duy nhất !\n";
    } else {
        cout << "đồ thị không có thứ tự topo duy nhất !\n";
    }
    return 0;
}
