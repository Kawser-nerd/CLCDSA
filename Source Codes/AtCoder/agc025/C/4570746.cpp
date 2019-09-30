//AVC?????????????????????????????
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
#include <cstring>

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
    int N;
    struct range {
        ll l;
        ll r;
        int id;
    };
    vector<range> ranges, L, R;

    void input() {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            ll l, r;
            cin >> l >> r;
            ranges.push_back(range{l, r, i});
        }
        L = R = ranges;

        sort(all(L), [](range a, range b) {
            return a.l < b.l;
        });

        sort(all(R), [](range a, range b) {
            return a.r < b.r;
        });
    }

    bool next_left(int lpt, int rpt, ll now) {
        return rpt < N && R[rpt].r < now;
    }

    bool next_right(int lpt, int rpt, ll now) {
        return lpt >= 0 && L[lpt].l > now;
    }


    //???left
    ll left() {
        int lpt = N - 1;
        int rpt = 0;
        ll now = 0ll;
        ll ret = 0ll;
        set<int> used;
        //?????
        if (R[rpt].r < now) {
            ll diff = abs(R[rpt].r - now);
            now = R[rpt].r;
            ret += diff;
            used.insert(R[rpt].id);
            rpt++;
        }
        while (true) {
            //????
            if (next_left(lpt, rpt, now)) {
                //??
                if (used.count(R[rpt].id) == 0) {
                    ll diff = abs(R[rpt].r - now);
                    now = R[rpt].r;
                    ret += diff;
                    used.insert(R[rpt].id);
                }
                rpt++;
            } else if (next_right(lpt, rpt, now)) {
                if (used.count(L[lpt].id) == 0) {
                    ll diff = abs(L[lpt].l - now);
                    now = L[lpt].l;
                    ret += diff;
                    used.insert(L[lpt].id);
                }
                lpt--;
            } else {
                ll diff = abs(now - 0);
                ret += diff;
                now = 0;
                break;
            }
        }
        return ret;
    }

    ll right() {
        int lpt = N - 1;
        int rpt = 0;
        ll now = 0ll;
        ll ret = 0ll;
        set<int> used;
        //?????
        if (L[lpt].l > now) {
            ll diff = abs(L[lpt].l - now);
            now = L[lpt].l;
            ret += diff;
            used.insert(L[lpt].id);
            lpt--;
        }
        while (true) {
            //????
            if (next_left(lpt, rpt, now)) {
                //??
                if (used.count(R[rpt].id) == 0) {
                    ll diff = abs(R[rpt].r - now);
                    now = R[rpt].r;
                    ret += diff;
                    used.insert(R[rpt].id);
                }
                rpt++;
            } else if (next_right(lpt, rpt, now)) {
                if (used.count(L[lpt].id) == 0) {
                    ll diff = abs(L[lpt].l - now);
                    now = L[lpt].l;
                    ret += diff;
                    used.insert(L[lpt].id);
                }
                lpt--;
            } else {
                ll diff = abs(now - 0);
                ret += diff;
                now = 0;
                break;
            }
        }
        return ret;
    }

    void solve() {
        input();
        ll lval = left();
        ll rval = right();
        ll ans = max(lval, rval);
        cout << ans << endl;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}