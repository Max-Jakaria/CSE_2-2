#include <bits/stdc++.h>
using namespace std;

const int N = 4;
vector<int> cols(N, 0);
vector<int> leftDiagonal(N * 2, 0);
vector<int> rightDiagonal(N * 2, 0);
vector<int> cur;

int placeQueens(int i) {
    int n = cols.size();

    //If all queens are placed then return true
    if (i == n) return 1;

    for (int j = 0; j < n; j++) {

        // Check if the queen can be placed
        if (cols[j] || rightDiagonal[i + j] || leftDiagonal[i - j + n - 1])
            continue;

        // mark the cell occupied
        cols[j] = 1;
        rightDiagonal[i + j] = 1;
        leftDiagonal[i - j + n - 1] = 1;
        cur.push_back(j + 1);

        if (placeQueens(i + 1))
            return 1;

        // remove the queen from current cell
        cur.pop_back();
        cols[j] = 0;
        rightDiagonal[i + j] = 0;
        leftDiagonal[i - j + n - 1] = 0;
    }
    return 0;
}


vector<int> nQueen(int n) {
    // If the solution exists
    if (placeQueens(0)) return cur;
    else return { -1};
}

int main() {
    int n = 4;
    vector<int> ans = nQueen(n);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}
