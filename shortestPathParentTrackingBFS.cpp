#include<bits/stdc++.h>
using namespace std;
vector<int> v[10]; //eta "adjacecncy list"
bool visited[10]; //kuno node visit hole tar value true hobe. ekhane index hocce ekekta node.
int level[10];//proti node/index er initial level hobe -1. sorbucco level hobe node er sob ceye boro valur soman. visited na hole level re-assign hobe ba level barbe.
int nodesParent[10]; //proti node/index er initial parent hobe -1. Usually srcNode 0 hoy. sourceNode er kuno parent hoy na, tai eta -1 e thakbe. Ekoi sorceNode e kuno specific node er parent ekoi tahakbe, tobe sourceNode change hole node parent change hote pare.
void bfs(int srcNode){
    memset(visited,false, sizeof(visited));
    memset(level,-1, sizeof(level));
    memset(nodesParent,-1, sizeof(nodesParent));
    queue<int> q;
    q.push(srcNode); //0
    visited[srcNode]=true;
    level[srcNode]=0;
    while(!q.empty()){
        int parent=q.front(); //parent node
        cout<<"parent "<<parent<<" level "<<level[parent]<<endl;
        q.pop();
    //"adjacency list" theke child gulu niye aste hobe. queue theke parent ber kore ana hoyeche.
       for(auto child:v[parent]){ //"adjacency list"theke parent er protiti child loop caliye ber kora ana hocce
        cout<<child<<" level "<<level[child]<<endl;
        if(visited[child]==false){ //visited array te zodi false thake tahole visit kora hoy ni. visit false hole kaj korbo.
          q.push(child);
          visited[child]=true;
          level[child]=level[parent]+1; //visited na hole parent er level er sathe 1 add hobe. ar zodi visited hoy tahole tar level count kora hoye geche.
          nodesParent[child]=parent; // queue theke ber howya node zodi visited na hoy, tahole parent er sob gulu child e parent ke assign kore dibo.
        }
        }
    }
}
int main(){
    int totalNodes, totalEdges;
    cin>>totalNodes>>totalEdges;
    while(totalEdges--){
        int a,b;
        //ekhane a and b er value 0-5 ( v[0,1,2,3,4,5] ) porzonto hobe. v er index ekekta node ke represent kore. v er ekekta index abar ekta kore vector hold kore, ei vector e oi node/index er sathe directly connected node guluke store kore.
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
         // ekhane v ekti array zar index 0-5 porzonto. and a,b er value 0-5 porzontoi hobe orthat v array er kuno na kuno index er soman. dhori a=0, b=1; tahole v[0/a] ekti array er moddhye a node era sathe connected node b push kora hoyeche. ekoivabe b er sathe a connected howyay v[1/b] te a node push kora hoyeche.
    }
    int srcNode; //ze node theke traverse shuru hobe
    cin>>srcNode;
    bfs(srcNode); //BFS algo level order e kaj kore. BFS shortestPath e travers kore.
    //print level from level array.
    cout<<"nodes level print"<<endl;
    for(int i=0; i<10; i++){
        //level array er protita index e hocce ekekta node ar index value hocce tar level;
        //i hocce node
        int lebel=level[i];
        cout<<i<<" level "<<lebel<<endl;
    }
    cout<<"destination printing bfs"<<endl;
    int des;
    cin>>des; //ei node muloto ekta index
    vector<int> path;
    while(des!=-1){
        cout<<des<<" ";
        path.push_back(des); //store reverse path in vector
        des=nodesParent[des];
    }
    return 0;
}
/*
input
6 9
0 1
1 5
2 3
3 5
1 3
4 0
0 2
1 4
4 5
0

output
parent 0 level 0
1 level -1
4 level -1
2 level -1
parent 1 level 1
0 level 0
5 level -1
3 level -1
4 level 1
parent 4 level 1
0 level 0
1 level 1
5 level 2
parent 2 level 1
3 level 2
0 level 0
parent 5 level 2
1 level 1
3 level 2
4 level 1
parent 3 level 2
2 level 1
5 level 2
1 level 1
nodes level print
0 level 0
1 level 1
2 level 1
3 level 2
4 level 1
5 level 2
6 level -1
7 level -1
8 level -1
9 level -1

*/