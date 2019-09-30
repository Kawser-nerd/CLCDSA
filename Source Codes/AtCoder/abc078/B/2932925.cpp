#include <iostream>

int main()
{
    int x, y, z; std::cin >> x >> y >> z;
    int canSitWidth = x - z;
    int cnt = 0;
    while(true) {
        if (canSitWidth - (y + z) >= 0) {
            cnt++;
            canSitWidth -= (y + z);
        } else {
            break;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}