#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const int maxN = 888;
char table[maxN][maxN];
int go[maxN][maxN];
bool used[maxN][maxN];


struct State {
    int I;
    int J;
    int Rem;
    int Act;
    State() {}
    State(int I, int J, int Rem, int Act) : I(I), J(J), Rem(Rem), Act(Act) {}
};

queue <State> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k;

bool on_board(int i, int j) {
    return i >= 1 && i <= n && j <= m && j >= 1;
}

int d[maxN][maxN];

int main(void) {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> table[i][j];
            if (table[i][j] == 'S') {
                q.push(State(i, j, k, 0));
            }
        }
    }
    queue<pair <int, int> > q1;
    while (!q.empty()) {
        auto cur = q.front();
        q1.push(make_pair(cur.I, cur.J));
        q.pop();
        if (cur.I == n || cur.I == 1 || cur.J == 1 || cur.J == m) {
            cout << 1 << endl;
            return 0;
        }
        if (cur.Rem == 0) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nI = dx[i] + cur.I;
            int nJ = dy[i] + cur.J;
            if (!used[nI][nJ] && on_board(nI, nJ) && table[nI][nJ] == '.') {
                used[nI][nJ] = true;
                q.push(State(nI, nJ, cur.Rem - 1, 1));
            }
        }
    }
    while (!q1.empty()) {
        auto cur = q1.front();
        q1.pop();
        if (cur.first == n || cur.first == 1 || cur.second == 1 || cur.second == m) {
            cout << 1 + (d[cur.first][cur.second] + k - 1) / k;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nI = dx[i] + cur.first;
            int nJ = dy[i] + cur.second;
            if (!used[nI][nJ] && on_board(nI, nJ)) {
                q1.push({nI, nJ});
                used[nI][nJ] = true;
                d[nI][nJ] = d[cur.first][cur.second] + 1;
            }
        }
    }





    return 0;
}