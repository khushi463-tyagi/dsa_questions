#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int m;
    int n;
    vector<vector<int>>adj;
    
public:
    Graph(int m,int n){
        this->m=m;
        this->n=n;
        adj.resize(m,vector<int>(n,0));
    }

    void addedge(int i,int j){
        adj[i][j]=1;
    }
    int get(int i,int j){
        return adj[i][j];
    }

    void dfs(int i,int j){
        if(i<0 || i>=m || j<0 ||j>=n ||adj[i][j]==0)return;
        adj[i][j]=0;
        vector<int> dx={1,0,-1,0};
        vector<int>dy={0,1,0,-1};

        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            dfs(nx,ny);
        }
    }
    void bfs(int a,int b){
        queue<pair<int,int>>pq;
        pq.push({a,b});
        adj[a][b]=0;
        while (!pq.empty())
        {
            auto f=pq.front();
            int i=f.first;
            int j=f.second;
            pq.pop();
            vector<int>dx={0,1,0,-1};
            vector<int>dy={1,0,-1,0};
            for(int k=0;k<4;k++){
                int nx = i+dx[k];
                int ny= j+dy[k];
                if(nx>=0 && ny>=0 && nx<m && ny<n && adj[nx][ny]==1)
                {
                    pq.push({nx, ny});
                    adj[nx][ny]=0;
                }
            }
        }
        
    }

};



int main(){
    int m,n;
    cout<<"enter dim m and n";
    cin>>m>>n;
    Graph g(m,n);
    cout<<"enter number of isl.";
    int k;
    cin>>k;
    for(int l=0;l<k;l++){
        cout<<"enter i j of islannd if exist";
        int i,j;
        cin>>i>>j;
        g.addedge(i,j);
    }
        
    
    int cnt=0;
    for(int a=0;a<m;a++){
        for(int b=0;b<n;b++){
            if(g.get(a,b)==1){
                cnt++;
               // g.dfs(a,b);
               g.bfs(a,b);
            }
        }
    }

    cout<<"no. of island"<<cnt;
    return 0;
}