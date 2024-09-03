#include<bits/stdc++.h>
using namespace std;
vector<int> v[100]; //eta "adjacecncy list"
bool visited[100]; //kuno node visit hole tar value true hobe. ekhane index hocce ekekta node.
void bfs(int srcNode){
    memset(visited,false, sizeof(visited));
    queue<int> q;
    q.push(srcNode); //0
    visited[srcNode]=true;
    while(!q.empty()){
        int parent=q.front(); //parent node
        cout<<"parent "<<parent<<endl;
        q.pop();
    //"adjacency list" theke child gulu niye aste hobe. queue theke parent ber kore ana hoyeche.
       for(auto child:v[parent]){ //"adjacency list"theke parent er protiti child loop caliye ber kora ana hocce
        cout<<child<<endl;
        if(visited[child]==false){ //visited array te zodi false thake tahole visit kora hoy ni. visit false hole kaj korbo.
          q.push(child);
          visited[child]=true;
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
    bfs(srcNode); //BFS algo level order e kaj kore.
    return 0;
}
/*
inputs
6 9 nodes edges
0 1
1 5
2 3
3 5
1 3
4 0
0 2
1 4
4 5
0 srcNode

output
parent 0
1
4
2
parent 1
0
5
3
4
parent 4
0
1
5
parent 2
3
0
parent 5
1
3
4
parent 3
2
5
1
*/