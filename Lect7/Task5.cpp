#include<iostream>
#include <string.h>

using std::cin, std::cout;

void print(int a, int s[], bool f[], int index) {
    if (a == index)  {
        for (int i = 0; i < index; i++) {
            cout<<s[i];
        }
        cout<<std::endl;
        return;
    }
    //backtrack
    for(int j = 1; j <= a; j++) {
        if (f[j] == false) {
            s[index] = j;
            f[j] = true;
            print(a, s, f, index + 1);
            f[j] = false;
        }
    }
}
int main() {
    int n;
    cin>>n;
    int a[n + 1];
    bool b[n + 1];
    memset(a, 0, sizeof(a));
    memset(b, false, sizeof(b));
    print(n, a, b, 0);
}