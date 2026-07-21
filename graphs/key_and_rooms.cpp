#include<bits/stdc++.h>

using namespace std;

class Soln {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        queue<int>p;
        p.push(0);
        while(!p.empty()){
            int f=p.front();
            p.pop();
            vis[f]=1;
            for(auto i:rooms[f]){
                if(vis[i]!=1){
                p.push(i);}
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0)return false;
        }
        return true;
    }
};

int main(){
    int n;
    cout<<"enter no. of rooms :";
    cin>>n;
    vector<vector<int>>rooms(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cout<<"enter no. of keys for this rooms :"<<i<<endl;
        cin>>k;
        cout<<"enter the rooms this key opens :";
        for(int j=0;j<k;j++){
            int key;
            cin>>key;
            rooms[i].push_back(key);
        }
    }
    Soln obj;
    if(obj.canVisitAllRooms(rooms)){
        cout<<"all rooms visit"<<endl;

    }
    else cout<<"can not visit all rooms"<<endl;
    
return 0;

}