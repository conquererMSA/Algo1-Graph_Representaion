#include<bits/stdc++.h>
using namespace std;
/*
Component graph hocce ekti graph er separeted duita ongsho. Ekta sub graph arekti sub graph theke sompurno alada. Ekahne ekti graph er duita source thake.
Zemon 0 er sathe 1 and 2 connected. Abar 3 er sathe 4 and 5 connected. Ekahne 012 and 345 duita alada graph. Eder moddhye kuno connection va path nei.
*/
vector<int> v[6];
bool visitedNode[6];
void dfs(int src){
    cout<<src<<endl;
    visitedNode[src]=true;
    for(int child:v[src]){
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
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // dfs(0);//012
    // dfs(3);//345
    //zodi prottyekti node connected hoto tahole ekti src diye dfs korle ekoi time e sob gulu node visited hoye zeto. Zehetu node gulu connected noy taole ekti src theke dfs er maddhyome sob gulu node ek time visit kora somvob noy.
    for(int i=0; i<n; i++){
        if(!visitedNode[i]){
            dfs(i);
        }
    }

    return 0;
}