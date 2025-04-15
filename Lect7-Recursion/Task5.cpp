#include<iostream>
using std::cin, std::cout;

int sum(int n) {
    if (n <= 10) return 1;
    return sum(n / 10) + 1;
}
int main() {
    int n;
    cin>>n;
    cout<<sum(n);
}