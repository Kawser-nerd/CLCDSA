#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

const int maxn = 333;

int n;
char s[maxn][maxn], t[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    REP(i, n) cin >> s[i];
    int answer = 0;
    REP(b, n) {
        REP(i, n) REP(j, n) t[i][j] = s[i][(j + b) % n];
        bool ok = 1;
        REP(i, n) REP(j, n) if (t[i][j] != t[j][i]) {
            ok = 0;
            break;
        }
        if (ok) answer += n;
    }
    cout << answer << "\n";
    return 0;
}