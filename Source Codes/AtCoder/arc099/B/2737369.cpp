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
#define eps 1e-15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//????????

ll snuke(ll n) {
    ll ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

ll next(ll num) {
    ll min_v = num;
    ll min_snuke = snuke(num);

    for (int i = 0; (ll) round(pow(10, i)) < num;) {
        //?i????????
//        if ((num % (int) round(pow(10, i)) * 10) / (int) round(pow(10, i)) == 9) {
        if ((num / (ll) round(pow(10, i))) % 10 == 9) {
            i++;
        } else {
            num += (ll) round(pow(10, i));
        }

        if (num * min_snuke < min_v * snuke(num)) {
            min_v = num;
            min_snuke = snuke(num);
        }
    }

    return min_v;
}

void solve() {
    int K;
    cin >> K;

    ll cur = 1ll;
    while (K--) {
        cout << cur << endl;
        cur = next(cur + 1);
    }

}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();


    return 0;
}