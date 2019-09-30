#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <functional>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
#define LOG(x) cout << #x << " := " << (x) << endl
#define _LOG(x) cout << "Momentai " << x << endl
typedef long long ll;
typedef long double Lf;

const int max_N = 1e5+5;
const int max_M = 35;

int N, L, Q;
int ar[max_N], nxt[max_N][max_M];

int get_next(int i) {
    if (i == N) return N;

    int l = i+1, r = N;
    while (l < r) {
        int m = (l+r+1) / 2;
        if (ar[m]-ar[i] > L) r = m-1;
        else l = m;
    }

    return l;
}

void init() {
    for (int i = 0; i <= N; ++i) nxt[i][0] = get_next(i);
    
    for (int i = 1; i < max_M; ++i)
        for (int j = 0; j <= N; ++j) {
            nxt[j][i] = nxt[nxt[j][i-1]][i-1];
        }
}

int calc_distance(int a, int b) {
    int ans = 0;
    
    for (int k = max_M-1; k >= 0; --k)
        if (nxt[a][k] <= b) {
            ans += (1 << k);
            a = nxt[a][k];
        }
    if (a != b) ++ans;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> ar[i];
    ar[N] = ar[N-1]+1;
    cin >> L >> Q;
    init();

    while (Q--) {
        int a, b; cin >> a >> b; --a; --b;
        if (a > b) swap(a, b);
        cout << calc_distance(a, b) << endl;
    }

    return 0;
}