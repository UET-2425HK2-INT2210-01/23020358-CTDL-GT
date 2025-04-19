#include<iostream>
using std::cin, std::cout;
//why would anyone use recursion to caculate power of a number :/
//recursively reduce the power(n) by 1 as we multi x with x
int sum(int x,int n) {
    if (n == 1) return x;
    return sum(x,n - 1) * x;
}
int main() {
    int x,n;
    cin>>x>>n;
    cout<<sum(x,n);
}