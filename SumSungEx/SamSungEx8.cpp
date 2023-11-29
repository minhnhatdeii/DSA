#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &stack1) {
    visited[v] = true;
    for (int neighbor: graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, stack1);
        }
    }
    stack1.push(v);
}

void topoSort(vector<vector<int>> &graph, vector<int> &result) {
    int v = graph.size() - 1;
    vector<bool> visited(v + 1, false);
    stack<int> mystack;

    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, mystack);
        }
    }

    int topo = 1;
    while (!mystack.empty()) {
        int vertex = mystack.top();
        mystack.pop();
        result[vertex] = topo++;
    }
}

int main() {
    int numVertices, numEdge;
    cin >> numVertices >> numEdge;

    vector<vector<int>> graph(numVertices + 1);
    vector<int> result(numVertices + 1, 0);

    for (int i = 0; i < numEdge; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    topoSort(graph, result);

    for (int i = 1; i <= numVertices; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
