#include<iostream>
#include<vector>
using std::cin, std::cout;
//quick sort
void sort(std::vector<int> &arr, int left, int right) {
    //take pivot in median of arr
    int mid = (right + left) / 2;
    int pivot = arr[mid];
    int i = left, j = right;
    while(i < j) {
        while(arr[i] < pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (i < right) {
        sort(arr, i, right);
    }
    if(j > left) {
        sort(arr, left, j);
    }
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
    sort(arr,0,n - 1);
    for (auto i : arr) {
        cout<<i<<" ";
    }
}