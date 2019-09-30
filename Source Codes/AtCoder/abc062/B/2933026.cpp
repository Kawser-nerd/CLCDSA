#include <iostream>

int main()
{
    int h, w; std::cin >> h >> w;
    char a[110][110];

    // ??
    for (int i = 0; i <= h + 1; i++) {
        for (int j = 0; j <= w + 1; j++) {
            if (i == 0 || i == h + 1) {
                a[i][j] = '#';
            } else if (j == 0 || j == w + 1) {
                a[i][j] = '#';
            } else {
                std::cin >> a[i][j];
            }
        }
    }

    // ??
    for (int i = 0; i <= h + 1; i++) {
        for (int j = 0; j <= w + 1; j++) {
            if (j == w + 1) std::cout << a[i][j] << std::endl;
            else            std::cout << a[i][j];
        }
    }
    return 0;
}