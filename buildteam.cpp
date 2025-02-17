//https://cses.fi/problemset/task/1668
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> visited;
vector<int> teams;

bool bipart(int s, int curr) {
    visited[s] = true;
    teams[s] = curr;
    int ncurr = (curr == 1) ? 2 : 1;
    
    for (auto u : adj[s]) {
        if (teams[u] == curr) {
            return false;
        }
        if (!visited[u]) {
            if (!bipart(u, ncurr)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n, false);
    teams.resize(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }

    bool works = true;
    for (int i = 0; i < n && works; i++) {
        if (teams[i] == 0) { 
            works = bipart(i, 1); 
        }
    }

    if (!works) {
        cout << "IMPOSSIBLE";
    } else {
        for (int i = 0; i < n; i++) {
            cout << teams[i] << ' ';
        }
    }

    return 0;
}
