#include<iostream>
using std::cin, std::cout;
//recursively divide number and take it's last digit and sum it up
int sum(int n) {
    if (n <= 10) return n;
    return sum(n / 10) + n % 10;
}
int main() {
    int n;
    cin>>n;
    cout<<sum(n);
}