#include <iostream>

using namespace std;

int main(){
    string a;
    getline(cin,a);
    for (int i = a.length()-1; i >=0 ; i--) {
        cout<<a[i];
    }
}