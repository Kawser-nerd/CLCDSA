#include <iostream>
#include <stdio.h>

int gcd(int a,int b){return b?gcd(b,a%b):a;}

void calc(long  N) {
    auto lcm = 2 * N / gcd(N, 2);
    std::cout << lcm << std::endl;
}

int main(int argc, char** argv) {
    long N;
    scanf("%ld", &N);
    calc(N);
    return 0;
}