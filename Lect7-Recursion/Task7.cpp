#include<iostream>
#include<cstring>
using std::cin, std::cout;

void sum(std::string n, int p) {
    if(p == n.length()) {
        return;
    }
    sum(n,p + 1);
    cout<<n[p];
}
int main() {
    std::string n;
    cin>>n;
    sum(n,0);
}