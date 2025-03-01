// Sorting Algorithms...
#include <bits/stdc++.h>
using namespace std;

// _________BUBBLE SORT__________
void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

// _________SELECTION SORT___________
void selectionSort(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }

        swap(arr[i], arr[minIdx]);
    }
}

// ___________QUICK SORT________
int partition(vector<int> &arr, int &low, int &high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        // Pivot element placed to right position
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
    }
}

// __________________MERGE SORT________________
void merge(vector<int> &arr, int &leftChildIdx, int &mid, int &rightChildIdx) {
    // Size of two arry
    int n1 = mid - leftChildIdx + 1;
    int n2 = rightChildIdx - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[leftChildIdx + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // For comparision issue
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    int i = 0, j = 0;
    for(int k=leftChildIdx; k<=rightChildIdx; k++){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &arr, int leftChildIdx, int rightChildIdx) {
    if (leftChildIdx < rightChildIdx) {
        int mid = (leftChildIdx+rightChildIdx) / 2;

        // Devide
        mergeSort(arr, leftChildIdx, mid);
        mergeSort(arr, mid + 1, rightChildIdx);

        // Conquer
        merge(arr, leftChildIdx, mid, rightChildIdx);
    }
}

// ______________HEAP SORT_________________
void heapify(vector<int> &arr, int n, int i) {
    int prntIdx = i;
    int leftChildIdx = 2 * i + 1;
    int rightChildIdx = 2 * i + 2;

    // If leftChild > parent
    if (leftChildIdx < n && arr[leftChildIdx] > arr[prntIdx])
        prntIdx = leftChildIdx;

    // If rightChild > patrent
    if (rightChildIdx < n && arr[rightChildIdx] > arr[prntIdx])
        prntIdx = rightChildIdx;

    // If prntIdx is not root, swap and continue heapifying
    if (prntIdx != i) {
        swap(arr[i], arr[prntIdx]);
        heapify(arr, n, prntIdx);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    
    // Build max heap (rearrange array)
    for(int i = (n/2)-1; i>=0; i--)
        heapify(arr, n, i);

    // Extract elements one by one from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move current root to end
        heapify(arr, i, 0);    // Heapify reduced heap
    }
}



int main(){
    vector<int> v = {10, 15, 5, 2, 12, 3};
    // bubbleSort(v);
    // selectionSort(v);
    // quickSort(v, 0, v.size() -1);
    // mergeSort(v, 0, v.size()-1);
    // heapSort(v);
    for(auto &it: v) cout<< it<<' ';
}