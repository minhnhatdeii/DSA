#include <bits/stdc++.h>
using namespace std;
int n, m;
set<int> adj[1001];
int degree[1001];

void euler(int v) {
    stack<int> st;
    vector<int> EC;
    st.push(v);
    while (!st.empty()) {
        int x = st.top();
        if (adj[x].size() != 0) {
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        } else {
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(begin(EC), end(EC));
    for (int x : EC) {
        cout << x << " ";
    }
}
bool hasEqualInAndOutDegree() {
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}
bool isConnected() {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}
bool hasEulerCycle() {
    if (!isConnected() || !hasEqualInAndOutDegree()) {
        return false;
    }
    return true;
}
bool isHamiltonCircuit(int m) {
    if (!isConnected()) {
        return false;
    }

    int degreeHamil[m];
    for (int i = 0; i < m; i++) {
        degreeHamil[i] = adj[i].size();
    }
    for (int i = 0; i < m; i++) {
        if (degreeHamil[i] < m / 2) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }
    if (hasEulerCycle()) {
        euler(1);
    } else {
        cout << "Khong co chu trinh Euler";
    }
    cout << endl;
    if(isHamiltonCircuit(n)) {
        cout << "Co chu trinh Hamilton";
    } else {
        cout << "Khong co chu trinh Hamilton";
    }
    return 0;
}

