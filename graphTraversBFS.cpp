#include<bits/stdc++.h>
using namespace std;
vector<int> v[6];
void bfs(int src){
     bool visited[6];
     memset(visited, false, sizeof(visited));
     queue<int> q;
     q.push(src);
     visited[src]=true;
     while(!q.empty()){
        int parent=q.front();
        q.pop();
        cout<<parent<<" "<<"connected with"<<endl;
        for(auto child:v[parent]){
            cout<<child<<" "<<"child of "<<parent<<endl;
            if(!visited[child]){
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
    return 0;
}