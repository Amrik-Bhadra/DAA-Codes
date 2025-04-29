#include<bits/stdc++.h>
using namespace std;

long long karatsuba(long long x, long long y){
    if(x < 10 || y < 10){
        return x * y;
    }

    int n = max(to_string(x).size(), to_string(y).size());
    int m = floor(n/2);

    long long pow10 = 1;
    for(int i = 0; i < m; i++) pow10 *= 10;   // calculate 10^m

    long long x1 = x / pow10;
    long long x2 = x % pow10;
    long long y1 = y / pow10;
    long long y2 = y % pow10;

    long long p1 = karatsuba(x1, y1);
    long long p2 = karatsuba(x2, y2);
    long long p3 = karatsuba(x1 + x2, y1 + y2);
    long long pcross = p3 - (p1 + p2);
    long long pfinal = (p1 * pow10 * pow10) + (pcross * pow10) + p2;

    return pfinal;
}

int main() {
    long long x = 4778, y = 6778;
    long long ans = karatsuba(x, y);
    cout << x << " * " << y << " = " << ans;
    return 0;
}