#include<bits/stdc++.h>
using namespace std;
vector<int> v[10];
int main(){
    int totalNodes, totalEdges;
    cin>>totalNodes>>totalEdges;
    while(totalEdges--){
        int a,b;
        //ekhane a and b er value 0-5 ( v[0,1,2,3,4,5] ) porzonto hobe. v er index ekekta node ke represent kore. v er ekekta index abar ekta kore vector hold kore, ei vector e oi node/index er sathe directly connected node guluke store kore.
        cin>>a,b;
        v[a].push_back(b);
        v[b].push_back(a);
         // ekhane v ekti array zar index 0-5 porzonto. and a,b er value 0-5 porzontoi hobe orthat v array er kuno na kuno index er soman. dhori a=0, b=1; tahole v[0/a] ekti array er moddhye a node era sathe connected node b push kora hoyeche. ekoivabe b er sathe a connected howyay v[1/b] te a node push kora hoyeche.

    }
    return 0;
}