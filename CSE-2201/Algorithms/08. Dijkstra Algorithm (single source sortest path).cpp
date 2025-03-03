// _____Single source shortest path...
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;
vector<pair<int, int>> g[N];
vector<int> dist(N, INF);

void dijkstra(int source){
    vector<bool> vis(N, 0);
    set<pair<int,int>> st;
    // Using set as a priority queue: {distance, vertex}
    st.insert({0, source});
    dist[source] = 0;

    while(!st.empty()){
        auto node = *st.begin();
        st.erase(st.begin());

        int v = node.second;
        int curr_dist = node.first;

        if(vis[v]) continue;
        vis[v] = 1;

        for(auto &child: g[v]){
            int child_v = child.first;
            int wt = child.second;
            // Main funda...
            int new_dist = curr_dist + wt;
            if(new_dist < dist[child_v]){
                dist[child_v] = new_dist;
                st.insert({new_dist, child_v});
            }
        }
    }
}

int main(){    
    int numOfV, numOfE;
    cin>> numOfV>> numOfE;
    for(int i=0; i<numOfE; i++){
        int x, y, wt;
        cin>> x>> y>> wt;
        g[x].push_back({y, wt});
    }
    int source, target;
    cin>> source>> target;
    dijkstra(source);
    cout<<(dist[target] == INF? -1: dist[target]);
    return 0;
}
/*
3 3
2 1 3
1 3 2
2 3 6
1 1
*/
