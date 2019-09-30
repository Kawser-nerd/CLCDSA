#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        int R, C, N; cin >> R >> C >> N;

        int answer = 0;
        if (N > (R * C + 1) / 2) {
            N = R * C - N;
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, -1, 0, 1};
            vector<int> edges[2];
            for (int i = 0; i < R; ++i)
                for (int j = 0; j < C; ++j) {
                    int p = 0;
                    for (int k = 0; k < 4; ++k) {
                        int newi = i + dx[k];
                        int newj = j + dy[k];
                        if (newi < 0 || newi >= R)
                            continue;
                        if (newj < 0 || newj >= C)
                            continue;
                        ++p;
                    }
                    edges[(i + j) % 2].push_back(p);
                }
            sort(edges[0].begin(), edges[0].end(), greater<int>());
            sort(edges[1].begin(), edges[1].end(), greater<int>());
            int answer1= 0 ,answer2 = 0;
            for (int i = 0; i < N; ++i) {
                answer1 += edges[0][i];
                answer2 += edges[1][i];
            }
            answer = R * (C - 1) + (R - 1) * C - max(answer1, answer2);
        }
        cout << "Case #" << test << ": " << answer << "\n";
    }
}
