//pseudo-code for calculate 2^n
#include <iostream>
using namespace std;

unsigned long long expo1(int n) {
    long long a = 1;
    for (int i = 1; i <= n; i++) {
        a *= 2;
    }
    return a;
}

unsigned long long expo2(int n) {
    return (1 << n);
}
/*
with those function, we will calculate:
    - expo1 has n step to calculate 2^n so the complexity should be O(n)
    - expo2 has constant step to calculate 2^n so the complexity should be O(1);
*/