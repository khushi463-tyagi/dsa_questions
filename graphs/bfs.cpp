#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int n;
    vector<vector<int>> adj;
    vector<bool> vis;

public:
    Graph(int n){
        this->n=n;
        adj.resize(n);
        vis.resize(n,false);
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    void bfs(int edge){
        queue<int> q;
        q.push(edge);
        vis[edge]=true;
        while(!q.empty()){
            int f=q.front();
            cout<<f;
            q.pop();
            for(int i:adj[f]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
            }

        }
    }

};




int main(){
    int n,m;
    cout<<"enter number of nodes:";
    cin>>n;
    Graph g(n);
    cout<<"enter number of edges : ";
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    int s;
    cout<<"what should be starting point";
    cin>>s;
    g.bfs(s);
    return 0;



}