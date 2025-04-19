#include<iostream>
#include<fstream>
#include<vector>
#include <string.h>
using std::vector;
std::ifstream input("matrix.txt");
std::ofstream output("matrix.out");
vector<vector<int>> arr;
void instream() {
    int m,n;
    input >> m >> n;
    //resize vector
    arr.resize(m + 1);
    for (int i = 0; i <= m; i++) {
        arr[i].resize(n + 1);
    }
    //set all number to 0
    for (auto &i : arr) memset(&i[0], 0, sizeof(i[0]) * i.size());
    //take numbers to arr
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            input>>arr[i][j];
        }
    }
}
//sum of 2D prefix
void prefix(vector<vector<int>> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        for (int j = 1; j < arr[i].size(); j++) {
            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }
}
//find max result and position
void result() {
    prefix(arr);
    int max = INT_MIN;
    int p1,l1,p2,l2;
    for (int i = 1; i < arr.size(); i++) {
        for (int j = 1; j < arr[i].size(); j++) {
            for (int m = i; m < arr.size(); m++) {
                for (int n = j; n < arr[i].size(); n++) {
                    if (arr[m][n] - arr[i - 1][n] - arr[m][j - 1] + arr[i - 1][j - 1] > max) {
                        max = arr[m][n] - arr[i - 1][n] - arr[m][j - 1] + arr[i - 1][j - 1];
                        p1 = i;
                        l1 = j;
                        p2 = m;
                        l2 = n;
                    }
                }
            }
        }
    }
    output<<p1<<" "<<l1<<" "<<p2<<" "<<l2<<" "<<max<<std::endl;
}
int main() {
    instream();
    result();
}
