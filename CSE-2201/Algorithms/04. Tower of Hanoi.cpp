#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from, char to, char via){
    if(n == 0) return;
    
    towerOfHanoi(n-1, from, via, to);
    printf("Move disk%d from %c to %c\n", n, from, to);
    towerOfHanoi(n-1, via, to, from);   
}

int main(){ 
    int n = 3;
    char from='A', to='B', via='C';
    towerOfHanoi(n, from, to, via);   
    return 0;
}