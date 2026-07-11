#include<bits/stdc++.h>
using namespace std;


    void floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
   //     if(color==image[sr][sc])return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int col=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int x=f.first;
            int y=f.second;

            vector<int>dx={-1,0,1,0};
            vector<int>dy={0,1,0,-1};
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0&& nx<m && ny>=0 && ny<n && image[nx][ny]==col){
                    q.push({nx,ny});
                    image[nx][ny]=color;

                }
            }

        }
    }

int main(){
    int m,n;
    cout<<"enter m and n";
    cin>>m>>n;
    vector<vector<int>>adj(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            cin>>adj[i][j];
        }
    }
    cout<<"adj crated";
    int sr,sc;
    cin>>sr>>sc;
    int col;
    cin>>col;
    floodFill(adj,sr,sc,col);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            cout<<adj[i][j];
        }
    }return 0;

}