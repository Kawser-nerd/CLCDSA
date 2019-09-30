#include <iostream>

using namespace std;

int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int ret = 0;
    for (int i = 0; i <= a; i++) {
        int sum_i = i * 500;
        if (sum_i > x)   break;

        for (int j = 0; j <= b; j++) {
            int sum_ij = i * 500 + j * 100;
            if (sum_ij > x)   break;

            for (int k = 0; k <= c; k++) {
                int sum_ijk = i * 500 + j * 100 + k * 50;
                if (sum_ijk == x)   ret++;
                else if (sum_ijk > x)   break;
            }
        }
    }

    cout << ret << endl;
    return 0;
}