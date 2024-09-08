#include<bits/stdc++.h>
using namespace std;
vector<int> graph[8];
bool visitedNode[8];
int totalVisited=0;
void dfs(int srcNode){
     totalVisited+=1;
     visitedNode[srcNode]=true;
     for(int child:graph[srcNode]){
        if(!visitedNode[child]){
            // dfs(child);
        }
     }
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int srcNode;
    cin>>srcNode;
    memset(visitedNode,false, sizeof(visitedNode));
    dfs(srcNode);
    cout<<totalVisited<<endl;
    return 0;
}