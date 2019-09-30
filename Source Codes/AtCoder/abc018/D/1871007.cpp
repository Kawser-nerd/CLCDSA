#include <algorithm>
#include <iostream>
using namespace std;

int N, M, P, Q, R;

int rewards[20][20];

int main() {
    cin >> N >> M >> P >> Q >> R;
    for (int j = 0; j < N; ++j) fill(rewards[j], rewards[j]+N, 0);
    for (int j = 0; j < R; ++j) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        rewards[x][y] = z;
    }

    int ans = 0;

    for (int b = 0; b < (1 << M); ++b) {
        int bit_count = 0;
        int ok_m[18];
        for (int j = 0; j < M; ++j) {
            ok_m[j] = ( (b & (1 << j)) != 0 ) ? 1 : 0;
            if (ok_m[j]) ++bit_count;
        }
        if (bit_count != Q) continue;

        int score[18];
        for (int j = 0; j < N; ++j) {
            score[j] = 0;
            for (int k = 0; k < M; ++k) {
                if (ok_m[k]) score[j] += rewards[j][k];
            }
        }

        sort(score, score+N);
        reverse(score, score+N);

        int c = 0;
        for (int j = 0; j < P; ++j) {
            c += score[j];
        }
        ans = max(ans, c);
    }

    cout << ans << endl;
    return 0;
}