#include <iostream>
#include <vector>

using namespace std;

int find(vector<vector<int>>& m) {
    int n = m.size();
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    dp[0][0] = m[0][0];
    
    for (int i = 1; i < n; ++i) {
        dp[0][i] = dp[0][i-1] + m[0][i];
    }
    
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i-1][0] + m[i][0];
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = m[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[n-1][n-1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }
    int result = find(m);

    cout << "độ dài đường đi ngắn nhất là : " << result << endl;

    return 0;
}
