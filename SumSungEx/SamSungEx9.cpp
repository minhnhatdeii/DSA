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

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        degree[x]++;
        degree[y]++;
    }

    euler(1);
}
