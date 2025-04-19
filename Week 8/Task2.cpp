#include<iostream>
#include<vector>
using std::cin, std::cout;
//merge function
void merge(std::vector<int> &arr, int l, int mid, int r) {
    std::vector<int> L(mid - l + 1), R(r - mid);
    for (int i = 0; i < L.size(); i++) {
        L[i] = arr[i + l];
    }
    for (int i = 0; i < R.size(); i++) {
        R[i] = arr[i + mid + 1];
    }
    int i = 0,j = 0, index = l;
    while(i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            arr[index] = L[i];
            i++;
        } else {
            arr[index] = R[j];
            j++;
        }
        index++;
    }
    while (i < L.size()) {
        arr[index] = L[i];
        i++;
        index++;
    }
    while (j < R.size()) {
        arr[index] = R[j];
        j++;
        index++;
    }
}
//merge Sort
void mergeSort(std::vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int m = (r + l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr,m + 1, r);
    merge(arr, l, m, r);
}
int main() {
    int n;
    cin>>n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin>>k;
        arr[i] = k;
    }
    mergeSort(arr,0,n - 1);
    for (auto i : arr) {
        cout<<i<<" ";
    }
}