#include<bits/stdc++.h>
using namespace std;
/*
Normal graph e ekti matro int diye ndoe declare kora zeto, kintu 2D Graph e node create korar jonn at least 2 ta dimension(row,col) lagbe. 2D Grid graph e valid row and col niye ekti node create hoy.
*/
const int r=3, c=4; //2D grid er row, column;
char d2Grid[r][c];
bool visitedNode[r][c];
vector<pair<int, int>> childPath={{0,1}, {0,-1},{-1,0},{1,0}}; //ekti nirdisto srcNode er dan, bam, upor, nich er child noder path(row, col) store kora ache.
bool isValid(int gr, int gc){ //ekhane kuno node er row col valid kina check kora hocce.
    if(gr<0||gr>=r||gc<0||gc>=c) return false;
    return true;
}
void dfs(int nr, int nc){
    cout<<nr<<" "<<nc<<endl;
    visitedNode[nr][nc]=true;
    for(int i=0; i<4; i++){ //dane, bame, upor, niche zawar jonno child path theke pair nete hobe.
        int newNodeRow=nr+childPath[i].first;
        int newNodeCol=nc+childPath[i].second;
        if(isValid(newNodeRow, newNodeCol)&&!visitedNode[newNodeRow][newNodeCol]){
            dfs(newNodeRow,newNodeCol);
        }
    }
}
int main(){
    memset(visitedNode, false, sizeof(visitedNode));
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin>>x;
            d2Grid[i][j]=x;

        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<d2Grid[i][j];

        }
        cout<<endl;
    }
    int sr, sc;
    cin>>sr>>sc;
    dfs(sr, sc); //src row, col change hole travers path change hobe.
    return 0;
}