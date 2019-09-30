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
    cin >> N >> Y;

    rep(i, 0, N + 1) {
        rep(j, i, N + 1) {
            int a = j - i, b = N - j;
            if (10000 * i + 5000 * a + 1000 * b == Y) {
                printf("%d %d %d\n", i, a, b);
                return 0;
            }
        }
    }
    printf("-1 -1 -1\n");
}