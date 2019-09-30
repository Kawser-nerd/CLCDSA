#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
const double PI = acos(0);


//????????


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<double, double> > vp;
    rep(i, 0, N) {
        double x, y;
        cin >> x >> y;
        vp.emplace_back(x, y);
    }

    const int freq = (int) 1e6;
    const double r = 1e11;

    vector<int> cnt(N);

    for (int i = 0; i < freq; ++i) {
        double theta = 4 * PI / freq * i;
        double x = r * cos(theta);
        double y = r * sin(theta);

        int id = -1;

        for (int j = 0; j < vp.size(); ++j) {
            if (id == -1) {
                id = j;
            } else {
                if ((x - vp[j].first) * (x - vp[j].first) + (y - vp[j].second) * (y - vp[j].second) <
                    (x - vp[id].first) * (x - vp[id].first) + (y - vp[id].second) * (y - vp[id].second)) {
                    id = j;
                }
            }
        }

        cnt[id]++;
    }


    cout << fixed << setprecision(9);
    for (int i = 0; i < N; ++i) {
        cout << 1.0 * cnt[i] / freq << endl;
    }


    return 0;
}