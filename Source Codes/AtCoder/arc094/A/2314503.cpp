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

    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];

    int odd = 0, even = 0;

    rep(i, 0, 3) {
        if (v[i] % 2 == 0) even++;
        else odd++;
    }


    if (even == 3 || odd == 3) {
        sort(all(v));
        ll ans = 0;
        ans += (v[2] - v[0]) / 2;
        ans += (v[2] - v[1]) / 2;
        cout << ans << endl;

    } else if (even == 2) {
        rep(i, 0, 3) {
            if (v[i] % 2 == 0) {
                v[i]++;
            }
        }
        ll ans = 1;
        sort(all(v));
        ans += (v[2] - v[1]) / 2;
        ans += (v[2] - v[0]) / 2;
        cout << ans << endl;

    } else if (odd == 2) {
        rep(i, 0, 3) {
            if (v[i] % 2 == 1) {
                v[i]++;
            }
        }
        ll ans = 1;
        sort(all(v));
        ans += (v[2] - v[1]) / 2;
        ans += (v[2] - v[0]) / 2;
        cout << ans << endl;
    }


    return 0;
}