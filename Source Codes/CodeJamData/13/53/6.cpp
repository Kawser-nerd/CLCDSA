#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int N, M, P;
int U[20], V[20], A[20], B[20];
int X[20];

int CX[20];
int bestmatch;
bool visited[20];
int adj[20][20];
void check(int cnt)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            adj[i][j] = i==j ? 0 : INF;
        }
    }
    for (int i = 0; i < M; ++i) {
        chmin(adj[U[i]][V[i]], B[i]);
    }
    int cost = 0;
    for (int i = 0; i < cnt ; ++i) {
        chmin(adj[U[CX[i]]][V[CX[i]]], A[CX[i]]);
        cost += A[CX[i]];
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                chmin(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    // cout << cost<<" " <<adj[0][1]<<": ";
    // pv(CX, CX+cnt);
    if (cost == adj[0][1]) {
        int match = 0;
        for (int i = 0; i < min(P, cnt); ++i) {
            if (CX[i] == X[i]) {
                ++match;
            } else {
                break;
            }
        }
        chmax(bestmatch, match);
    }
}

void dfs(int u, int cnt)
{
    if (u == 1) {
        check(cnt);
        return;
    }

    for (int i = 0; i < M; ++i) {
        if (U[i] == u && !visited[V[i]]) {
            visited[V[i]] = true;
            CX[cnt] = i;
            dfs(V[i], cnt + 1);
            visited[V[i]] = false;
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for (int CN = 1; CN <= T; ++CN) {
        cin >> N >> M >> P;
        for (int i = 0; i < M; ++i) {
            cin >> U[i] >> V[i] >> A[i] >> B[i];
            --U[i]; --V[i];
        }
        for (int i = 0; i < P; ++i) {
            cin >> X[i];
            --X[i];
        }

        bestmatch = 0;
        dfs(0, 0);

        cout << "Case #" << CN << ": ";
        if (bestmatch == P) {
            cout << "Looks Good To Me" << endl;
        } else {
            cout << X[bestmatch] + 1 << endl;
        }
    }

    return 0;
}
