#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, e;
    cin>>n>>e;
    vector<int> graphMat[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        graphMat[a].push_back(b);
        graphMat[b].push_back(a);
    }
    //ekhane graphMat 0 hocce ekti vector, 0 index/node er sathe ze ze node connected tha ai vector e ache.
    int node; //kun node er connection dekhte cay.
    cin>>node;
    for(int i=0; i<graphMat[node].size(); i++){
        cout<<graphMat[node][i]<<" ";
    }
    return 0;
}