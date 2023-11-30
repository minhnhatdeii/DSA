
//Do phuc tap O(n).

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int count(const vector<pair<int, int>> &edges, int m) {
    int dem = 0;
    unordered_set<int> visV;

    for (const auto &edge: edges) {
        int hash = edge.first * (m + 1) + edge.second;
        if (!visV.insert(hash).second) {
            dem++;
        }
    }
    return dem;
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
    int res = count(edges, numVertical);
    cout << res << endl;
    return 0;
}
