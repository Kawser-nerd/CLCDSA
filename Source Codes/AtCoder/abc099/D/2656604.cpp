#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int N, C; cin >> N >> C;
    int d[C][C];
    int count[3][C];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < C; i++)
        for (int j = 0; j < C; j++)
            cin >> d[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int c; cin >> c;
            count[(i + j) % 3][c - 1]++;
        }
    }

    int ans = 1e9;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            if (i == j) continue;
            for (int k = 0; k < C; k++) {
                if ( i == k || j == k ) continue;

                int tmp = 0;
                for (int l = 0; l < C; l++)
                    tmp += d[l][i] * count[0][l];
                for (int l = 0; l < C; l++)
                    tmp += d[l][j] * count[1][l];
                for (int l = 0; l < C; l++)
                    tmp += d[l][k] * count[2][l];
                if (ans > tmp) ans = tmp;
            }
        }
    }
    cout << ans << endl;
}