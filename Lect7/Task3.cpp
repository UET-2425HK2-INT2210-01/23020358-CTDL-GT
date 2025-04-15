#include<iostream>
using std::cin,std::cout;

int gcd(int a, int b) {
    a = (a < 0) ? a * -1 : a;
    b = (b < 0) ? b* -1 : b;
    return (b == 0) ? a : gcd(b, a % b);
}
int main() {
    int n,k;
    cin>>n>>k;
    cout<<gcd(n,k);
}