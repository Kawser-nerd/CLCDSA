#include <iostream>

using namespace std;

int main() {
    int H, W, t, ans = 0;
    int c[10][10];

    cin >> H >> W;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            cin >> t;
            if (t != -1) { ans += c[t][1]; }
        }
    }
    cout << ans << endl;

    return 0;
}