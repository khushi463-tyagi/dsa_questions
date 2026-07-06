#include<bits./stdc++.h>

using namespace std;
class Graph
{
private:
    void bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        int n = graph.size();

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor = 0; neighbor < n; ++neighbor) {
                if (graph[node][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

public:
 int countProvinces(const vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);

        int provinces = 0;

        for (int city = 0; city < n; ++city) {
            if (!visited[city]) {
                ++provinces;
                bfs(city, graph, visited);
            }
        }

        return provinces;
    }
   
};




int main(){
    int n;
    cout<<"enter no. of cities :";
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));
    cout<<"enter matrix:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    Graph soln;
    cout<<"no. of pr."<<soln.countProvinces(graph);
    return 0;
}