#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, e;
    //ekhane n hocce ekti graph er total number of node. e hocce sei graph er total number of edges. Edge songkhokbar matrix er input nibo.
    cin>>n>>e;
    int graphMat[n][n];
    //node gulur value hobe n-1...
    memset(graphMat,0, sizeof(graphMat));
    while(e--){
        int a,b;
        cin>>a>>b;
        graphMat[a][b]=1; //a, b node er moddye connection ache.
        graphMat[b][a]=1; //a, b node er moddye connection ache. undirected graph e ei conncetion dite hoy. Kintu directed grap e lage na
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<graphMat[i][j]<<" ";
        }
        cout<<endl;
    }
    if(graphMat[0][2]){
        cout<<"connected"<<endl;
    }else cout<<"not connected"<<endl;

    return 0;
}