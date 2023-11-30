#include <bits/stdc++.h>
using namespace std;

set<int> adj[1005];
int lev[1005];
int n, m;

void euler(int v) {
    stack<int> st;
    vector<int> myvec;
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
            myvec.push_back(x);
        }
    }
    reverse(begin(myvec), end(myvec));
    for (int x : myvec) {
        cout << x << " ";
    }
}
bool equal() {
    for (int i = 1; i <= n; i++) {
        if (lev[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

bool conect() {
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

bool eulercycle() {
    if (!conect() || !equal()) {
        return false;
    }
    return true;
}

bool hamilton(int m) {
    if (!conect()) {
        return false;
    }

    int levHamil[m];
    for (int i = 0; i < m; i++) {
        levHamil[i] = adj[i].size();
    }
    for (int i = 0; i < m; i++) {
        if (levHamil[i] < m / 2) {
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
        lev[x]++;
        lev[y]++;
    }
    if (eulercycle()) {
        euler(1);
    } else {
        cout << "Khong co chu trinh Euler";
    }
    cout << endl;
    if(hamilton(n)) {
        cout << "Co chu trinh Hamilton";
    } else {
        cout << "Khong co chu trinh Hamilton";
    }
    return 0;
}

