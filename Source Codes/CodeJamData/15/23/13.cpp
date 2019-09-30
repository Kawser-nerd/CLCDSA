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
const long long inf64 = ((long long)1 << 60) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int MAXN = 2000;

int x[MAXN], num[MAXN];
long long m[MAXN];

int main () {
    ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tc;
    cin >> tc;

    for (int ti = 0; ti < tc; ++ti) {
        int n;
        cin >> n;

        int tot = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> num[i] >> m[i];
            tot += num[i];
        }

        long long lT = 1;
        long long rT = inf64;

        while (lT < rT) {
            long long mT = (lT + rT) / 2;

            long long cur_sum = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < num[i]; ++j) {
                    cur_sum = min(inf64, cur_sum + (mT + (m[i] + j) * x[i]) / 360 / (m[i] + j));
                }
            }

            if (cur_sum > 2 * tot) {
                rT = mT;
            } else {
                lT = mT + 1;
            }
        }

        long long T = lT;
        vector <pair <long long, int> > ev;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < num[i]; ++j) {
                long long cur_t = (360 - x[i]) * (m[i] + j);
                int k = 1;
                while (cur_t <= T) {
                    ev.pb(mp(cur_t, (k == 1 ? 1 : -1)));
                    k++;
                    cur_t += 360 * (m[i] + j);
                }
            }
        }

        sort (ev.begin(), ev.end());

        int ans = tot;
        int cur = tot;

        for (int i = 0; i < sz(ev); ++i) {
            cur -= ev[i].sc;
            ans = min(ans, cur);
        }

        cerr << ti << endl;
        cout << "Case #" << ti + 1 << ": " << ans << "\n";
    }


	return 0;
}
