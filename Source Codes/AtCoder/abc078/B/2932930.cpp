#include <iostream>

int main()
{
    int x, y, z, cnt = 0; std::cin >> x >> y >> z;
    x -= z;
    while(true) {
        if (x - (y + z) >= 0) {
            cnt++;
            x -= (y + z);
        } else {
            break;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}