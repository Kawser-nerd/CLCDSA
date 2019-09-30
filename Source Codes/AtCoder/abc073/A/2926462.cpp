#include <iostream>

int main()
{
    int n; std::cin >> n;
    bool ok = false;
    while(n) {
        if (n % 10 == 9) {
            ok = true;
            break;
        }
        n /= 10;

    }

    std::cout << (ok ? "Yes" : "No") << std::endl;
    return 0;
}