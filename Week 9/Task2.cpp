#include<iostream>
#include <string.h>
using std::cin, std::cout;
int main() {
    int n, W;
    cin>>n>>W;
    int a[n + 1],b[n + 1];
    //a[n] = weight
    //b[n] = value
    for (int i = 0; i < n; i++) {
        cin>>a[i]>>b[i];
    }
    int l[n + 1][W + 1];
    //memset array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            l[i][j] = 0;
        }
    }
    //apply Dynamic Programming
    //with l[i][j] is max value stastified
    //we have l[i][j] = max(l[i-1][j - a[i]] + b[i], l[i - 1][j]) if we has a[i] < j
    //else we take value l[i][j] = l[i - 1][j]
    //heil Dynamische Programmierung
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (a[i] <= j) {
                l[i][j] = std::max(l[i - 1][j - a[i]] + b[i], l[i - 1][j]);
            } else {
                l[i][j] = l[i - 1][j];
            }
        }
    }
    cout<<l[n][W];
}