#include<bits/stdc++.h>
using namespace std;
/*
 DFS hocce ekti recursive algorithme. DFS recursive algo ekti graph er sob gulu node niye kaj korte sob ceye lomba route/cost visit kore. Kuno ekti node er children visit korle oi children er children visit e cole zay. Kuno ekta node er sob gulu children eker por ek print kore na.

 //Depth First Search (DFS) shortest path maintain kore na.DFS ekti recursive algorithme. DFS children to children visit korar jonno graph e sob ceye lomba rastha diye visit kore. DFS order maintain kore na.
 **Puru graph randomly travers korar jonno DFS Algorithme use hoy.
*/
const int N=100;
vector<int> v[N];
bool visitedNode[N];

void dfs(int srcNode){
    //DFS protomei graph er sourceNode niye kaj kore.
    cout<<srcNode<<endl; //kaj kora hoyeche
    visitedNode[srcNode]=true; //kaj korar por visitedNode e true kora hoyeche.
    for(int child:v[srcNode]){ //adjacency_list theke oi node er child ber kora hocce.
        if(!visitedNode[child]){ //child er visited zodi false hoy tahole dfs e child diye call kora hocce and abar recursive call hobe. ar zodi visited true hoy tahole recursive call hobe na.
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
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int srcNode;
    cin>>srcNode;
    memset(visitedNode,false, sizeof(visitedNode));
    dfs(srcNode);
    return 0;
}