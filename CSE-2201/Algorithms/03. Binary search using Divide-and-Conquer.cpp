#include <bits/stdc++.h>
using namespace std;

// ____________Divide-and-conquer___________________
int binSearch(vector<int> &arr, int low, int high, int &val){
    if(low > high) return -1;

    int mid = low + (high-low)/2;
    if(arr[mid] == val) return mid;

    if(arr[mid] > val) binSearch(arr, low, mid-1, val);
    else binSearch(arr, mid+1, high, val);
}

// ________________Normal_______________
// int binSearch(vector<int> &arr, int low, int high, int &val){
    
//     while(low <= high){
//         int mid = low + (high-low) / 2;

//         if(arr[mid] == val) return mid;
//         if(arr[mid] > val) high = mid-1;
//         else low = mid+1;
//     }

//     return -1;
// }

int main(){
    vector<int> arr = {5,7,2,10,48,6};
    sort(arr.begin(), arr.end());

    int n = arr.size()-1, val = 48;

    cout<< binSearch(arr, 0, n, val);
    return 0;
}
