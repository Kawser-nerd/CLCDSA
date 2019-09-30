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
#define INFl ((1LL << 55) - 1)
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//????????

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> a(N), b(N);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> b[i];

    rep(i, 0, N) {
        if (!(a[i] == b[i]) && !(a[i] > b[i] * 2)) {
            cout << -1 << endl;
            return 0;
        }
    }

    const int lim = 51;

    vector<vector<ll> > dist(lim, vector<ll>(lim, INFl));


    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < lim; j++) {
            if (i == j) dist[i][j] = 0ll;
            if (i > j * 2) {
                int diff = i - j;
                for (int k = 1; k <= diff; k++) {
                    if (diff % k == 0 && k > j) {
                        dist[i][j] = min((1ll << (k)), dist[i][j]);
                    }
                }
            }
        }
    }

    for (int k = 0; k < lim; k++) {
        for (int i = 0; i < lim; i++) {
            for (int j = 0; j < lim; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

//    cout << "--" << endl;
//    for(int i = 0; i < 20; i++){
//        printf("%2d |",i);
//        for(int j = 0; j < 20; j++){
//            if(dist[i][j] == INFl){
//                printf("  INF ");
//            }else {
//                printf("%5lld ", dist[i][j]);
//            }
//        }
//        cout << endl;
//    }

    vector<bool> used(N, false);
    vector<vector<bool> > vvb(N, vector<bool>(51, false));

    rep(i, 0, a.size()) {
        vvb[i][a[i]] = true;
    }

    ll ans = 0LL;
    for (int i = 50; i >= 1; i--) {
        ll lower = 1LL << i;
        bool useFlag = false;
        for (int j = 0; j < N; j++) {
            bool trueFlag = true;
            rep(k, 0, 51) {
                if (vvb[j][k]) {
                    //k???????????
                    if (!(dist[k][b[j]] & lower)) {
                        auto check = [&]() {
                            for (int bit = 50; bit > i; bit--) {
                                ll cost = dist[k][b[j]];
                                if ((cost >> bit & 1) && !(ans >> bit & 1)) {
                                    return false;
                                }
                            }
                            return true;
//                            return false;
                        };

                        if(check()) trueFlag = false;
                    }
                }
            }
            if (trueFlag) useFlag = true;
        }
        if (useFlag) {
            ans |= lower;
            rep(j, 0, N) {
                for (int k = 50; k >= 0; k--) {
                    if (vvb[j][k]) {
                        vvb[j][k % i] = true;
                    }
                }
            }
        } else {
            rep(j, 0, N) {
//                vvb[j][i] = false;
            }
        }
    }
    cout << ans << endl;


    return 0;
}