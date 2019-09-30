#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
const int MAX_N = 100;
const int MAX_H = 200;
const int MIN_DAMAGE = 20;
const int MAX_TURNS = MAX_N * ((MAX_H + MIN_DAMAGE - 1) / MIN_DAMAGE) + 1;

int N, Princess, Tower, Health[MAX_N], Gold[MAX_N], DP[MAX_N][MAX_H + 1][MAX_TURNS + 1];

void Clear() {
    N = Princess = Tower = 0;
    for (int i = 0; i < MAX_N; ++i)
        Health[i] = Gold[i] = 0;
    for (int i = 0; i < MAX_N; ++i)
        for (int h = 0; h <= MAX_H; ++h)
            for (int t = 0; t <= MAX_TURNS; ++t)
                DP[i][h][t] = -oo;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCases;
    cin >> testCases;
    for (int test = 1; test <= testCases; ++test) {
        Clear();
        cin >> Princess >> Tower >> N;
        for (int i = 0; i < N; ++i)
            cin >> Health[i] >> Gold[i];
        DP[0][Health[0]][1] = 0;
        for (int i = 0; i < N; ++i) {
            for (int h = Health[i]; h > 0; --h) {
                for (int t = 0; t <= MAX_TURNS; ++t) {
                    if (t > 0) {
                        int win = 0;
                        if (Princess >= h)
                            win = Gold[i];
                        DP[i][max(0, h - Princess)][t - 1] = max(DP[i][max(0, h - Princess)][t - 1], DP[i][h][t] + win);
                    }
                    if (t + 1 <= MAX_TURNS)
                        DP[i][max(0, h - Tower)][t + 1] = max(DP[i][max(0, h - Tower)][t + 1], DP[i][h][t]);
                }
            }
            if (i + 1 < N) {
                for (int t = 0; t <= MAX_TURNS; ++t)
                    DP[i + 1][Health[i + 1]][t] = DP[i][0][t];
            }
        }
        int answer = 0;
        for (int t = 0; t <= MAX_TURNS; ++t)
            answer = max(answer, DP[N - 1][0][t]);
        cout << "Case #" << test << ": " << answer << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
