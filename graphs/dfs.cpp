#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;
    vector<bool> vis;

public:
    Graph(int n) {
        this->n = n;
        adj.resize(n + 1);
        vis.resize(n + 1, false);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    void dfs(int node) {
        vis[node] = true;
        cout << node << " ";

        for (int child : adj[node]) {
            if (!vis[child]) {
                dfs(child);
            }
        }
    }
}; 

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cin >> start;

    g.dfs(start);

    return 0;
}