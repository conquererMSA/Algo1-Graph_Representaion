#include<bits/stdc++.h>
using namespace std;
char d2Grid[3][4];
bool visitedNode[3][4];
vector<pair<int,int>> childPath={{0,1}, {0,-1},{-1,0},{1,0}};
int level[3][4];
bool isValid(int gr, int gc){ //ekhane kuno node er row col valid kina check kora hocce.
    if(gr<0||gr>=3||gc<0||gc>=4) return false;
    return true;
}
void bfs(int srcR, int srcC){
   queue<pair<int,int>> q;
   q.push({srcR, srcC});
   level[srcR][srcC]=0;
   visitedNode[srcR][srcC]=true;
   cout<<srcR<<" "<<srcC<<endl;
   while(!q.empty()){
    pair<int,int> parent=q.front();
    int row=parent.first;
    int col=parent.second;
    q.pop();
    for(pair<int,int> child:childPath){
        int childRow=child.first+row;
        int childCol=child.second+col;
        if(isValid(childRow,childCol)&&!visitedNode[childRow][childCol]){
            visitedNode[childRow][childCol]=true;
            level[childRow][childCol]+=1;
            q.push({childRow,childCol});
            // bfs(childRow, childCol);
        }

        }
   }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin>>d2Grid[i][j];
        }
    }
    memset(visitedNode, false, sizeof(visitedNode));
    memset(level, -1, sizeof(level));
    int srcR, srcC;
    cin>>srcR>>srcC;
    bfs(srcR,srcC);
    return 0;
}