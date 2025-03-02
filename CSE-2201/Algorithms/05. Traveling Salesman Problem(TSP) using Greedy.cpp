#include <bits/stdc++.h>
using namespace std;

int findNext(vector<vector<int>> &g, vector<bool> &visited, int curr, int n){
    int minD = INT_MAX, next = -1;
    for(int j = 0; j < n; j++)
        if(!visited[j] && g[curr][j] && g[curr][j] < minD)
            minD = g[curr][j], next = j;
    return next;
}

void tsp(vector<vector<int>> &g, int start){
    int n = g.size(), cost = 0, curr = start;
    vector<bool> visited(n, false);
    vector<int> price(n+1);
    
    visited[start] = true;
    price[0] = start;
    
    for(int i = 1; i < n; i++){
        int next = findNext(g, visited, curr, n);
        price[i] = next;
        cost += g[curr][next];
        visited[next] = true;
        curr = next;
    }
    
    cost += g[curr][start];
    price[n] = start;
    
    for(int i = 0; i <= n; i++)
        cout << price[i] << (i < n ? " -> " : "\n");
    cout << cost;
}

int main(){
    vector<vector<int>> g = {
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };
    tsp(g, 0);
    return 0;
}