#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int MAXN = 20;

int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool in_field (int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int num_neighbors[2][5];

int main () {
//  ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tc;
    cin >> tc;

    for (int ti = 0; ti < tc; ++ti) {
        int num;
        cin >> n >> m >> num;

        if (num <= (n * m + 1) / 2) {
            cout << "Case #" << ti + 1 << ": " << 0 << "\n";
            continue;
        }

        num = n * m - num;

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 5; ++j) {
                num_neighbors[i][j] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cur = 0;
                for (int k = 0; k < 4; ++k) {
                    if (in_field(i + dx[k], j + dy[k])) {
                        cur++;
                    }
                }
                num_neighbors[(i + j) % 2][cur]++;
            }
        }

        int ans[2];

        for (int c = 0; c < 2; ++c) {
            ans[c] = n * (m - 1) + m * (n - 1);
            int cur = num;
            for (int i = 4; i >= 0; --i) {
                ans[c] -= i * min(num_neighbors[c][i], cur);
                cur -= min(num_neighbors[c][i], cur);
            }
        }

        cout << "Case #" << ti + 1 << ": " << min(ans[0], ans[1]) << "\n";
    }

	return 0;
}
