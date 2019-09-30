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
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//????????
class Solve {
public:
    void input() {

    }

    void solve() {
        input();
        int H, W;
        cin >> H >> W;
        vector<vector<int> > c(H + 2, vector<int>(W + 2));
        int sh, sw;
        int gh, gw;
        rep(i, 0, H) {
            rep(j, 0, W) {
                char tmp;
                cin >> tmp;
                if (tmp == '.') c[i][j] = 0;
                else if (tmp == '#') c[i][j] = 1;
                else if (tmp == 's') {
                    sh = i;
                    sw = j;
                    c[i][j] = 0;
                } else if (tmp == 'g') {
                    gh = i;
                    gw = j;
                    c[i][j] = 0;
                }
            }
        }

        vector<vector<int> > dist(H + 2, vector<int>(W + 2, INF));
        dist[sh][sw] = 0;
        struct cell {
            int h;
            int w;
            int d;
        };
        deque<cell> que;
        que.push_back(cell{sh, sw, 0});
        while (!que.empty()) {
            cell top = que.front();
            que.pop_front();

            int h = top.h;
            int w = top.w;
            int d = top.d;

            int dh[] = {0, -1, 0, 1};
            int dw[] = {1, 0, -1, 0};

            for (int k = 0; k < 4; ++k) {
                int nh = h + dh[k];
                int nw = w + dw[k];
                if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
                int nd = d + c[nh][nw];

                if (nd < dist[nh][nw]) {
                    cell ncell{nh, nw, nd};
                    dist[nh][nw] = nd;
                    if (c[nh][nw] == 0) {
                        que.push_front(ncell);
                    } else {
                        que.push_back(ncell);
                    }
                }
            }
        }

        int goaldist = dist[gh][gw];

        if (goaldist <= 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}