#include<iostream>
#include<fstream>
#include<vector>
std::ifstream input("numbers.txt");
std::ofstream output("numbers.sorted");
std::vector<int> arr;
void infromfile() {
    int a;
    while(input >> a) {
        arr.push_back(a);
    }
    input.close();
}
void sort(std::vector<int> &arr, int left, int right) {
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
void wirtefile() {
    for (auto i : arr) {
        output << i << " ";
    }
}
int main() {
    infromfile();
    sort(arr, 0, arr.size() - 1);
    wirtefile();
}