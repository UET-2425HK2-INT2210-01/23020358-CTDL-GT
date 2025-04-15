#include<iostream>
using std::cin, std::cout;

int sum(int x,int n) {
    if (n == 1) return x;
    return sum(x,n - 1) * x;
}
int main() {
    int x,n;
    cin>>x>>n;
    cout<<sum(x,n);
}