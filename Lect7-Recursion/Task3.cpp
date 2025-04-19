#include<iostream>
using std::cin, std::cout;
//this is 2025 and no one want to calculate fibonacci with recursion tho :/
int sum(int n) {
    if (n == 0 || n == 1) return n;
    return sum(n - 1) + sum(n - 2);
}
int main() {
    int n;
    cin>>n;
    cout<<sum(n);
}