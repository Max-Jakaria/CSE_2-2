#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int lcs(int i, int j){
    if(i == 0 || j == 0) return 0;
    int ans = max(lcs(i-1, j), lcs(i, j-1));
    
    ans = max(ans, lcs(i-1, j-1) + (s1[i-1] == s2[j-1]));
    return ans;
}

int main(){  
    cin>> s1>> s2;
    cout<< "ans: "<<lcs(s1.size(), s2.size());
    return 0;
}