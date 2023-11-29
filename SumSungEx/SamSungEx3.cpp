
//Do phuc tap O(n).

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countParallelEdges(const vector<pair<int, int>> &edges, int m) {
    int cnt = 0;
    unordered_set<int> visitedV;

    for (const auto &edge: edges) {
        int hash = edge.first * (m + 1) + edge.second;
        if (!visitedV.insert(hash).second) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int numVertical, numEdge;
    cin >> numVertical;
    cin >> numEdge;
    vector<pair<int, int>> edges;
    for (int i = 0; i < numEdge; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }
    int parallelEdges = countParallelEdges(edges, numVertical);
    cout << parallelEdges << endl;
    return 0;
}
