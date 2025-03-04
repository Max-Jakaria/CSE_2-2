#include <bits/stdc++.h>
using namespace std;

const int N = 20;
vector<int> col(N);
vector<int> leftD(N);
vector<int> rightD(N);
vector<int> cur;

bool isPlaced(int i, int &n){
    if(i == n) return true;

    for(int j=0; j<n; j++){
        if(col[j] || leftD[i-j + n-1] || rightD[i+j])
            continue;

        cur.push_back(j+1);
        col[j] = 1;
        leftD[i-j + n-1] = 1;
        rightD[i + j] = 1;

        if(isPlaced(i+1, n)) return true;

        cur.pop_back();
        col[j] = 0;
        leftD[i-j + n-1] = 0;
        rightD[i + j] = 0;
    }

    return false;
}

vector<int> nQueen(int &n){
    if(isPlaced(0, n)){
        return cur;
    }
    else return {-1};
}

int main(){
    int n=4;
    vector<int> ans = nQueen(n);
    for(auto &it: ans)
        cout<<it<<' ';

    return 0;
}
