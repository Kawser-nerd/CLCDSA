#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

using R = double;
const int MN = 110;

int N;
vector<int> g[MN];
char c[MN];


char ans[MN];
int idx[MN];

string calc(int p) {
    vector<string> v;
    int m = 0;
    for (int d: g[p]) {
        v.push_back(calc(d));
    }
    for (string s: v) {
        m += (int)s.size();
    }
    iota(idx, idx+m, 0);
    random_shuffle(idx, idx+m);
    int u = 0;
    for (string s: v) {
        int f = (int)s.size();
        sort(idx+u, idx+u+f);
        for (int i = 0; i < f; i++) {
            ans[idx[u+i]] = s[i];
        }
        u += f;
    }
    ans[u] = '\0';
    string s, s2 = ans;
    if (p != N) s += c[p];
    return s + s2;
}
void solve2() {

    int m;
    cin >> m;
    string B[10];
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    constexpr int all = 6000;
    int co[m];
    fill_n(co, m, 0);
    srand(time(NULL));
    for (int i = 0; i < all; i++) {
        string str = calc(N);
//        cout << str << endl;
        for (int j = 0; j < m; j++) {
            if (str.find(B[j]) != string::npos) {
                co[j]++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        printf(" %.20lf", 1.0*co[i]/all);
    }
    printf("\n");
}
void solve() {
    cin >> N;
    for (int i = 0; i <= N; i++) {
        g[i].clear();
    }
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i]; a[i]--;
        if (a[i] == -1) a[i] = N;
        g[a[i]].push_back(i);
    }
    string s;
    cin >> s;
    for (int i = 0; i < N; i++) {
        c[i] = s[i];
    }
    solve2();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:", t);
        solve();
    }
    return 0;
}