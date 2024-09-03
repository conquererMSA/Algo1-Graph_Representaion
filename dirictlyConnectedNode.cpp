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
    //ekti nirdisto node er sathe connected node er songkha ber korte hobe..
    int node; //ai node ke base dhore, bfs diye level track rakhte hobe. etake base dhorle er sathe direclt connected sob gulu node er level hobe 1. Tar mane 1 level er sob gulu node ber kore ante hobe.
    cin>>node;
    bfs(node);
    // int levelOfNode=level[node];
    int totalConnctedNodes=0;
    for(int i=0; i<totalNodes; i++){
        if(level[i]==1) totalConnctedNodes+=1;
    }
    cout<<totalConnctedNodes<<endl;
    
   return 0;
}
/*
*/