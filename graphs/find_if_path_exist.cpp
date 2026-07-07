#include<bits/stdc++.h>
using namespace std;

int main(){
    int e;
    cout<<"enter no. of edges";
    cin>>e;
    int n;
    cout<<"enter no. of nodes";
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    queue<int>q;
    int source;
    int destination;
    cout<<"enter source and destination";
    cin>>source>>destination;
    vector<int>vis(n,0);
    vis[source]=1;
    q.push(source);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto i:adj[f]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }

        }
    }
    if(vis[destination]){
        cout<<"path exist";
    }
    else{
        cout<<"no path exist";
    }
return 0;

}