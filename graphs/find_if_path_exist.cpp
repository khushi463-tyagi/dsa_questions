#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool pathExists(int n, vector<vector<int>> &adj, int source, int destination) {

        vector<int> vis(n, 0);
        queue<int> q;

        vis[source] = 1;
        q.push(source);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for (int neigh : adj[node]) {
                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }

        return false;
    }
};

int main() {

    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);

    cout << "Enter the edges:\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);      
    }

    int source, destination;
    cout << "Enter source and destination: ";
    cin >> source >> destination;

    Solution obj;

    if (obj.pathExists(n, adj, source, destination))
        cout << "Path Exists\n";
    else
        cout << "No Path Exists\n";

    return 0;
}