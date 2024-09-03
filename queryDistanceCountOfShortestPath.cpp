#include<bits/stdc++.h>
using namespace std;
vector<int> v[10];
bool visited[10];
int level[10];
int nodesParent[10];
void bfs(int srcNode){
    memset(visited,false, sizeof(visited));
    memset(level,-1, sizeof(level));
    memset(nodesParent,-1, sizeof(nodesParent));
    queue<int> q;
    q.push(srcNode);
    visited[srcNode]=true;
    level[srcNode]=0;
    while(!q.empty()){
        int parent=q.front();
        q.pop();
       for(auto child:v[parent]){
        if(visited[child]==false){ 
          q.push(child);
          visited[child]=true;
          level[child]=level[parent]+1;
          nodesParent[child]=parent; 
        }
        }
    }
}
int main(){
    int totalNodes, totalEdges;
    cin>>totalNodes>>totalEdges;
    while(totalEdges--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
   int queries;
   cin>>queries;
   while(queries--){
    int src, des;
    cin>>src>>des;
    bfs(src);
    cout<<level[des]<<endl; //level array sourceNode onuzaye protita node er distance track rakhe. soursce node theke level zoto, soursce node theke distance toto.
    }
    return 0;
}
/*
*/