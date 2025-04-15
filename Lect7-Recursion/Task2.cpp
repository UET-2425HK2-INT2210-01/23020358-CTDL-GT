#include<iostream>
using std::cin, std::cout;

int sum(int n) {
    if (n == 1) return 1;
    return sum(n-1) * n;
}
int main() {
    int n;
    cin>>n;
    cout<<sum(n);
}