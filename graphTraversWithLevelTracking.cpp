#include<bits/stdc++.h>
using namespace std;
vector<int> v[6];
int level[6];
void bfs(int src){
     bool visited[6];
     memset(level,-1, sizeof(level));
     memset(visited, false, sizeof(visited));
     queue<int> q;
     q.push(src);
     level[src]=0;
     visited[src]=true;
     while(!q.empty()){
        int parent=q.front();
        q.pop();
        cout<<parent<<" "<<"connected with"<<endl;
        for(auto child:v[parent]){
            cout<<child<<" "<<"child of "<<parent<<endl;
            if(!visited[child]){
                level[child]=level[parent]+1;
                q.push(child);
                visited[child]=true;
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
    int src;
    cin>>src;
    bfs(src);
    for(int i=0; i<=n; i++){
        cout<<"level of "<<i<<" is "<<level[i]<<endl;
    }
    return 0;
}