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
    bfs(0);
    int lebel;
    cin>>lebel;
    vector<int> levelNodes;
    for(int i=0; i<6; i++){ //ekti level er nodes pawar jonno index porzonto loop calate hoy. node value 0-5 porzonto hote pare.
       if(level[i]==lebel){
        levelNodes.push_back(i);
       }
    }
    sort(levelNodes.begin(), levelNodes.end(), greater<int>());
    for(int i:levelNodes){
        cout<<i<<" ";
    }
   return 0;
}
/*
*/