#include<iostream>
using std::cin, std::cout;
//just why? :>
int sum(int n) {
    if (n == 0) return 0;
    return sum(n-1) + n;
}
int main() {
    int n;
    cin>>n;
    cout<<sum(n);
}