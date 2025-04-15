#include<iostream>
using std::cin, std::cout;

int sum(int n) {
    if (n == 0 || n == 1) return n;
    return sum(n - 1) + sum(n - 2);
}
int main() {
    int n;
    cin>>n;
    cout<<sum(n);
}