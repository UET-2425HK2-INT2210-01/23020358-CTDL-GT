#include<iostream>
#include <string.h>
bool b[1000005];
int arr[1000005];
bool state = false;
//backtrack
void backtrack(int s, int n) {
    if (s == 0) {
        state = true;
        return;
    } else if (s < 0) {
        return;
    } else {
        //backtrack for sum = sum - arr[i]
        for (int i = 0; i < n; i++) {
            //set arr[i] as visited
            b[i] = true;
            if (b[i] == true) {
                //backtrack
                backtrack(s - arr[i], n);
            }
            //set arr[i] as not visited to check other possible
            b[i] = false;
        }
    }
}
int main(){
    int s,n;
    std::cin>>n>>s;
    for (int i = 0; i < n; i++){
        std::cin>>arr[i];
    }
    memset(b, false, sizeof(b));
    backtrack(s,n);
    (state == true) ? std::cout<<"YES" : std::cout<<"NO";
}