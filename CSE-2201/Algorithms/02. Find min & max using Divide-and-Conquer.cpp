#include <bits/stdc++.h>
using namespace std;

int minimum(vector<int> &arr, int low, int high){
    if(low == high) return arr[low];

    int mid = low + (high-low) / 2;
    int minLeft = minimum(arr, low, mid);
    int minRight = minimum(arr, mid+1, high);
    
    return (minLeft < minRight)? minLeft: minRight;
}

int maximum(vector<int> &arr, int low, int high){
    if(low == high) return arr[low];

    int mid = low + (high - low) / 2;
    int maxLeft = maximum(arr, low, mid);
    int maxRight = maximum(arr, mid+1, high);

    return (maxLeft > maxRight)? maxLeft: maxRight;
}

int main(){
    vector<int> arr = {5,7,2,10,48,6};

    int n = arr.size()-1;
    cout<< minimum(arr, 0, n)<< '\n';
    cout<< maximum(arr, 0, n)<< '\n';
    return 0;
}
