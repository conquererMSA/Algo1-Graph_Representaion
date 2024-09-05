#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10];
bool visitedNode[10];
int totalVisited=0;
void dfs(int srcNode){
     totalVisited+=1;
     visitedNode[srcNode]=true;
     for(int child:graph[srcNode]){
        if(!visitedNode[child]){
            dfs(child);
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
    memset(visitedNode,false, sizeof(visitedNode));
    vector<int> totalComponentsNodes;
    for(int i=0; i<n; i++){
        //zodi visited hoy, tahole ager component e count hoye geche. Ar visited na hole eta notun ekta component and count hobe.
        if(!visitedNode[i]){
            totalVisited=0;
            dfs(i);
            totalComponentsNodes.push_back(totalVisited);
        }
      
    }
    sort(totalComponentsNodes.begin(), totalComponentsNodes.end());
    for(auto eachComponentNodes:totalComponentsNodes){
        cout<<eachComponentNodes<<" ";
    }
    return 0;
}