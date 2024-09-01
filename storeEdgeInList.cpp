#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, e;
    cin>>n>>e;
    vector<pair<int, int>> edges;
    while(e--){
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }
    for(pair<int, int> eP: edges){
        cout<<eP.first<<" "<<eP.second<<endl;
    }
    return 0;
}