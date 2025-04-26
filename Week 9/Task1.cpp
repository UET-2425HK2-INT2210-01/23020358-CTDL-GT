#include<iostream>
#include <string.h>
int arr[1000005];
bool state = false;
//dp = Dynamische Programmierung >:))))
void dp(int s, int n) {
    //we use a boolean s*n size table to save the cal result
    bool a[n + 1][s + 1];
    memset(a, false, sizeof a);
    //the a[0][0] is always true and this is base condition
    a[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (j >= arr[i]) {
                //logic handle
                //if the previous number has a sum equal it-self then the next number which
                //is previous plus some number in array will exist
                //which led to the equation a[i][j] = a[i - 1][j - arr[i]] || a[i - 1][j]
                //the a[i - 1][j] is a case when this current number wont be add to the calculated sum
                //the a[i][j] only not possible when there are no a[i - 1][j] and no a[i - 1][j - arr[i]]
                a[i][j] = a[i - 1][j - arr[i]] || a[i - 1][j];
            } 
        }
    }
    //in some case there are no possible sum use 1 or ... to n value 
    //so we has to traversal through all possible number to find if the sum exist
    for (int i = 1; i <= n; i++) {
        if (a[i][s]) {
            state = true;
            return;
        }
    }
}
int main(){
    int s,n;
    std::cin>>n>>s;
    for (int i = 1; i <= n; i++){
        std::cin>>arr[i];
    }
    dp(s,n);
    (state == true) ? std::cout<<"YES" : std::cout<<"NO";
}