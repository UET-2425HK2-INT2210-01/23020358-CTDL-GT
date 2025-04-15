#include<iostream>
#include <string.h>

using std::cin, std::cout;

void print(int a, int s[], int index) {
    if (a == index)  {
        for (int i = 0; i < index; i++) {
            cout<<s[i];
        }
        cout<<std::endl;
        return;
    }
    s[index] = 0;
    print(a, s, index + 1);
    s[index] = 1;
    print(a, s, index + 1);
}
int main() {
    int n;
    cin>>n;
    int a[n + 2];
    memset(a, 0, sizeof(a));
    print(n, a, 0);
}