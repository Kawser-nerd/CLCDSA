#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//??
typedef long long int ll;
using namespace std;
const double eps = 1e-16;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//????????
class Solve {
public:
    int H, W;
    vector<vector<char>> c;
    using P = pair<int, int>;
    P start, goal;

    void input() {
        cin >> H >> W;
        c.resize(H + 2, vector<char>(W + 2, '#'));

        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                cin >> c[i][j];
                if (c[i][j] == 's') {
                    start = make_pair(i, j);
                } else if (c[i][j] == 'g') {
                    goal = make_pair(i, j);
                }
            }
        }
    }

    double getBright(P locate, int time) {
        if (c[locate.first][locate.second] == '#') return -1.0;
        if (c[locate.first][locate.second] == 's' || c[locate.first][locate.second] == 'g') return 10.0;
        return (c[locate.first][locate.second] - '0') * pow(0.99, time);
    }

    /**
     * ???lim???????????(lim??????)
     * @param lim
     * @return
     */
    double canpass(double lim) {
        vector<vector<bool> > used(H + 2, vector<bool>(W + 2, false));
        queue<pair<int, P>> que;

        used[start.first][start.second] = true;
        que.emplace(0, start);

        while (!que.empty()) {
            auto top = que.front();
            que.pop();
            int time = top.first;
            int h = top.second.first;
            int w = top.second.second;

            int dh[] = {-1, 0, 1, 0};
            int dw[] = {0, -1, 0, 1};

//            if (used[h][w]) continue;
//            used[h][w] = true;


            for (int k = 0; k < 4; ++k) {
                int nh = h + dh[k];
                int nw = w + dw[k];

                double cost = getBright(P(nh, nw), time + 1);
                if (!used[nh][nw] && (cost > lim || abs(cost - lim) < eps)) {
                    used[nh][nw] = true;
                    que.emplace(time + 1, P(nh, nw));
                }
            }
        }

        return used[goal.first][goal.second];
    }

    void solve() {
        input();

        if (!canpass(0.0)) {
            cout << -1 << endl;
            return;
        }
//        double ans = canpass();
//        if (ans < 0) {
//            cout << -1 << endl;
//            return;
//        }

        double ng = 10.0;
        double ok = 0.0;

        rep(_, 0, 40) {
            double mid = (ok + ng) / 2.0;
            if (canpass(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        cout << fixed << setprecision(10) << ok << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}