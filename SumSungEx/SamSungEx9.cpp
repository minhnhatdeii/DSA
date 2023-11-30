#include <bits/stdc++.h>
using namespace std;
int n, m;
set<int> adj[1005];
int lev[1005];

void euler(int v) {
    stack<int> myStack;
    vector<int> myvec;
    myStack.push(v);
    while (!myStack.empty()) {
        int x = myStack.top();
        if (adj[x].size() != 0) {
            int y = *adj[x].begin();
            myStack.push(y);
            adj[x].erase(y);
        } else {
            myStack.pop();
            myvec.push_back(x);
        }
    }
    reverse(begin(myvec), end(myvec));
    for (int x : myvec) {
        cout << x << " ";
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        lev[x]++;
        lev[y]++;
    }

    euler(1);
}
