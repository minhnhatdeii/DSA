#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int numVertices, vector<vector<int>>& adjacencyList) {
    vector<int> indegree(numVertices, 0);
    queue<int> q;
    vector<int> result;

    // Tính bậc vào (indegree) của mỗi đỉnh
    for (const vector<int>& neighbors : adjacencyList) {
        for (int neighbor : neighbors) {
            indegree[neighbor]++;
        }
    }

    for (int i = 0; i < numVertices; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        result.push_back(vertex);

        for (int neighbor : adjacencyList[vertex]) {
            indegree[neighbor]--;

            // Nếu bậc vào của đỉnh kề giảm về 0, thêm vào hàng đợi
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {

    int numVertices, numEdge;
    cin >> numVertices >> numEdge;

    vector<vector<int>> adjList(numVertices);
    for (int i = 0; i < numEdge; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    vector<int> sortedVertices = topologicalSort(numVertices, adjList);


    for (int vertex : sortedVertices) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
