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
int N;
ll C;
ll x[100000], v[100000];

ll left() {
    vector<ll> lcost(N, 0LL), rcost(N, 0LL);

    lcost[0] = v[0];
    rep(i, 1, N) {
        lcost[i] = lcost[i - 1] + v[i];
    }
    rep(i, 0, N) {
        lcost[i] -= x[i];
    }

    rcost[N - 1] = v[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        rcost[i] = rcost[i + 1] + v[i];
    }
    rep(i, 0, N) {
        rcost[i] -= (C - x[i]);
        rcost[i] -= (C - x[i]);
    }

    lcost[0] = max(lcost[0], 0ll);
    rep(i, 1, N) {
        lcost[i] = max(lcost[i], lcost[i - 1]);
    }
    rcost[N - 1] = max(rcost[N - 1], 0LL);
    for (int i = N - 2; i >= 0; i--) {
        rcost[i] = max(rcost[i], rcost[i + 1]);
    }
    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans = max(ans, lcost[i] + rcost[i + 1]);
    }
    ans = max(ans,lcost[N-1]);
    return ans;

}

ll right() {
    vector<ll> lcost(N, 0LL), rcost(N, 0LL);

    lcost[0] = v[0];
    rep(i, 1, N) {
        lcost[i] = lcost[i - 1] + v[i];
    }
    rep(i, 0, N) {
        lcost[i] -= x[i];
        lcost[i] -= x[i];
    }

    rcost[N - 1] = v[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        rcost[i] = rcost[i + 1] + v[i];
    }
    rep(i, 0, N) {
        rcost[i] -= (C - x[i]);
    }

    lcost[0] = max(lcost[0], 0ll);
    rep(i, 1, N) {
        lcost[i] = max(lcost[i], lcost[i - 1]);
    }
    rcost[N - 1] = max(rcost[N - 1], 0LL);
    for (int i = N - 2; i >= 0; i--) {
        rcost[i] = max(rcost[i], rcost[i + 1]);
    }
    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans = max(ans, lcost[i] + rcost[i + 1]);
    }
    ans = max(ans, rcost[0]);
    return ans;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> C;

    rep(i, 0, N) {
        cin >> x[i] >> v[i];
    }

    if(N == 1){
        ll ans = max({v[0] - x[0], v[0] - (C - x[0]), 0ll});
        cout << ans << endl;
        return 0;
    }

    ll ans = max(right(),left());
    cout << ans << endl;


    return 0;
}