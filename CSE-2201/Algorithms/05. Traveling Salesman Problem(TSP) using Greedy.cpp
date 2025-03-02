#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<vector<int>> g;
vector<bool> vis(N, false);

int findNext(int cur, int n){
    int minD = INT_MAX, next = -1;

    for(int j=0; j<n; j++){
        if(!vis[j] && g[cur][j] && g[cur][j] < minD){
            minD = g[cur][j];
            next = j;
        }
    }

    return next;
}

void tsp(int start){
    int n = g.size(), cost=0, cur = start;
    
    vector<int> travel(n+1);
    
    vis[start] = true;
    travel[0] = start;
    
    for(int i=1; i<n; i++){
        int next = findNext(cur, n);
        travel[i] = next;
        cost += g[cur][next];
        vis[next] = true;
        cur = next;
    }
    
    cost += g[cur][start];
    travel[n] = start;
    
    for(int i = 0; i <= n; i++){
        cout <<travel[i] <<(i<n ? "-> ": "\n");
    }

    cout <<cost;
}

int main(){
    g = {
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };
    tsp(0);
    
    return 0;
}
