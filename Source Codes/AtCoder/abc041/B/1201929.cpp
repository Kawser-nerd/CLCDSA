#include <iostream>
#include <math.h>
#include <string>


int main() {
    long long a, b, c;
    long M = (pow(10, 9) + 7);

    std::cin >> a >> b >> c;
    // (a * b) % M = {a%M * b%M} %M
    std::cout << (long long) a*b%M * c%M << std::endl;
}