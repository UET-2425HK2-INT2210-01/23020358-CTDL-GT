#include<iostream>
using std::cin, std::cout;
//why we don't run a for loop instead of this
int sum(int n) {
    if (n == 1) return 1;
    return sum(n-1) * n;
}
int main() {
    int n;
    cin>>n;
    cout<<sum(n);
}