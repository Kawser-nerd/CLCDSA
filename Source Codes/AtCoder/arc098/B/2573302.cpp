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
//#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
//#define EXIST(s, e) ((s).find(e)!=(s).end())
//#define SORT(c) sort(begin(c),end(c))
//#define pb emplace_back
//#define MP make_pair
//#define SZ(a) int((a).size())

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

    int N;
    cin >> N;
    vector<ll> A(N), pl(N + 1), xo(N + 1);
    rep(i, 0, N) cin >> A[i];

    rep(i, 0, N) {
        pl[i + 1] = pl[i] + A[i];
        xo[i + 1] = xo[i] ^ A[i];
    }

    int l = 0, r = 1;
    ll ans = 0ll;
    while (r < N + 1) {
        while (pl[r] - pl[l] != (xo[r] ^ xo[l])) {
            l++;
        }
        ans += r - l;
        r++;
    }

    cout << ans << endl;

    return 0;
}