#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define rep(i, a, N) for(int i = a; i < N; i++)
#define rrep(i, a, N) for(int i = a; i >= N; i--)

int N, Y;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> c(N), s(N), f(N);
    rep(i, 0, N - 1) {
        scanf("%d %d %d", &c[i], &s[i], &f[i]);
    }

    rep(i, 0, N) {
        int t = 0;
        rep(j, i, N -1) {
            if (t < s[j]) t = s[j];
            else if (t % f[j] == 0);
            else t += f[j] - t % f[j];
            t += c[j];
        }
        printf("%d\n", t);
    }
}