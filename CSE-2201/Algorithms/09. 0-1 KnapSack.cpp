// _______0/1 KnapSack__________
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> weight(N);
vector<int> profit(N);

long long zeroOneKnapSack(int n, int W){
    vector<long long> dp(W+1, 0);

    for(int i=0; i<n; i++){
        for(int w = W; w>=0; w--){
            if(weight[i] <= w){
                dp[w] = max(dp[w], dp[w - weight[i]] + profit[i]);
            }
        }
    }

    return dp[W];
}

int main(){
    int n, W; cin>> n>> W;
    for(int i=0; i<n; i++){
        cin>> weight[i]>> profit[i];
    }

    cout<< zeroOneKnapSack(n, W);
    return 0;
}
