#include<bits/stdc++.h>
using namespace std;
vector<int> v[10];
int level[10];
int par[10];
void bfs(int src){
     bool visited[10];
     memset(level,-1, sizeof(level));
     memset(visited, false, sizeof(visited));
     memset(par, -1, sizeof(par));
     queue<int> q;
     q.push(src);
     level[src]=0;
     visited[src]=true;
     while(!q.empty()){
        int parent=q.front();
        q.pop();
        for(auto child:v[parent]){
            // cout<<child<<endl;
            if(!visited[child]){
                level[child]=level[parent]+1;
                q.push(child);
                visited[child]=true;
                par[child]=parent;
            }
        }
     }
}
int main(){
    int n, e;
    cin>>n>>e;
    while(e--){
       int a,b;
       cin>>a>>b;
       v[a].push_back(b);
       v[b].push_back(a);
    }
    int src,des;
    cin>>src;
    //shortest_path of des
    cin>>des;
    bfs(src);
    int x=des;
    vector<int> path;
    while(x!=-1){
        path.push_back(x);
        x=par[x];
    }
    reverse(path.begin(), path.end());
    for(int c:path){
        cout<<c<<endl;
    }
    return 0;
}