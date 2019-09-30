#include <iostream>

int main() {
    int n;  std::cin >> n;
    int harshed = 0;
    for (int i = n; i; i /= 10) harshed += i % 10;
    if (n % harshed == 0)   std::cout << "Yes" << std::endl;
    else                    std::cout << "No" << std::endl;
    return 0;
}