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
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//????????


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, h, w;
    cin >> H >> W >> h >> w;
//    int ini_n = (int) (1e8);
    int x, y;
//    x = 114514;
    x = int(1e9 / (1000 * 1000));
    y = -(h * w - 1) * x - 1;
    vector<vector<ll> > a(H, vector<ll>(W, x));

    ll sum_v = 0LL;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            auto check = [&]() {
                return (i + 1) % h == 0 && (j + 1) % w == 0;
            };
            if (check()) {
//                a[i][j] = -(h * w);
//                sum_v -= (1 + h * w);
                a[i][j] = y;
            }
        }
    }
    rep(i, 0, H) {
        rep(j, 0, W) {
//            if (a[i][j] < 0) {
//                a[i][j] -= ini_n;
//            } else {
//                a[i][j] += ini_n;
//            }
            sum_v += 1LL * a[i][j];
        }
    }

    if (sum_v > 0) {
        cout << "Yes" << endl;
        rep(i, 0, H) {
            rep(j, 0, W) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No" << endl;
        //?????
//        rep(i, 0, H) {
//            rep(j, 0, W) {
//                cout << a[i][j] << " ";
//            }
//            cout << endl;
//        }
    }


    return 0;
}