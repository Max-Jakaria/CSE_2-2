// _____________LCS using DP______________
#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int const N = 1e4;
int dp[N][N];

int lcs(int i, int j){
    if(i == 0 || j == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = max(lcs(i-1, j), lcs(i, j-1));
    
    ans = max(ans, lcs(i-1, j-1) + (s1[i-1] == s2[j-1]));
    return dp[i][j] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin>> s1>> s2;
    cout<< "ans: "<<lcs(s1.size(), s2.size());
    return 0;
}
