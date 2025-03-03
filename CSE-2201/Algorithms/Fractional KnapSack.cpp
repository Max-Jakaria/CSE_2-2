// _________Fractional KnapSack______________
#include <bits/stdc++.h>
using namespace std;

vector<pair<double, pair<int, int>>> items;

double fractionalKnapSack(int W) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), greater<>());

    double maxProfit = 0.0;

    for (const auto &item : items) {
        if (W == 0) break;
        
        int weight = item.second.first;
        int profit = item.second.second;

        int takeWeight = min(W, weight);
        maxProfit += (double)profit * takeWeight / weight;
        W -= takeWeight;
    }

    return maxProfit;
}

int main() {
    int n, W;
    cin >> n >> W;

    for (int i = 0; i < n; i++) {
        int weight, profit;
        cin >> weight >> profit;
        double ratio = (double)profit / weight;
        items.push_back({ratio, {weight, profit}});
    }

    cout << fixed << setprecision(2) << fractionalKnapSack(W);
}
/*
3 50
10 60
20 100
30 120

output: 240.00
*/
