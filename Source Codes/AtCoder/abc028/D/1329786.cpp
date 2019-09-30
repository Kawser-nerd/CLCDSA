#include <iostream>
#include <stdio.h>
using namespace std;

using ull = unsigned long long;

int main(){
    ull N, K;
    cin >> N >> K;

    ull total = 6 * (K - 1) * (N - K) + 3 * (N - 1) + 1;
    double ans = (double)(total) / (double)(N * N * N);
    printf("%.10f", ans);
    return 0;
}