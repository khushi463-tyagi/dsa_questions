#include<bits/stdc++.h>
using namespace std;

class Graph{
    int m;
    int n;
    vector<vector<int>>adj;

public:
    Graph(int m,int n){
        this->m=m;
        this->n=n;
        adj.resize(m,vector<int>(n,0));
    }
    void addEdge(int i,int j){
        adj[i][j]=1;
    }
    int get(int i,int j){
        cout<<adj[i][j];
    }
    void dfs(int i,int j,int m,int n){
        adj[i][j]=2;
        int dirx[]={0,1,0,-1};
        int diry[]={1,0,-1,0};
        for(int k=0;k<4;k++){
            int nx=i+dirx[k];
            int ny=j+diry[k];
            if(nx>=0 && ny>=0 && nx<m && nx<n && adj[nx][ny]==1){
                dfs(nx,ny,m,n);
            }
        }

    }

}



int main(){
    int m,n;
    cout<<"enter m and n :";
    cin>>m>>n;
    Graph g(m,n);
    cout<<"enter 1 for island and 0 for water";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            if(val==1)addEdge(i,j);

        }

    }
    int j=0;
    for(int i=0;i<n;i++){
        if(g.get(i,j)==1){
            g.dfs(i,j,m,n);
        }
    }
    int j=m-1;
    for(int i=0;i<n;i++){
        if(g.get(i,j)==1){
            g.dfs(i,j,m,n);
        }
    }
    int i=0;
    for(int j=0;j<m;j++){
        if(g.get(i,j)==1){
            g.dfs(i,j,m,n);
        }
    }
    int i=n-1;
    for(int j=0;j<m;j++){
        if(g.get(i,j)==1){
            g.dfs(i,j,m,n);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(g.get(i,j)==2)cout<<"X";
            else cout<<"O";
        }
        cout<<endl;
    }





}