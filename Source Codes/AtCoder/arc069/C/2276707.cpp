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

    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i, 0, N) cin >> a[i];

    vector<ll> C, X, Y;
    map<ll, int> mp;
    mp[0] = 0;
    C.push_back(0LL);
    X.push_back(0LL);
    Y.push_back(0LL);
    ll max_v = 0;
    for (int i = 0; i < N; ++i) {
        if (max_v < a[i]) {
            max_v = a[i];
            C.push_back(a[i]);
            mp[a[i]] = i + 1;
            X.push_back(0LL);
            Y.push_back(1LL);
//            Y[mp[a[i]]]++;
        } else {
            int it = lower_bound(all(C), a[i]) - C.begin();
            X[it] += a[i] - C[it - 1];
            Y[it - 1]++;
        }
    }
    for(int i = Y.size() - 1; i > 0;i--){
        Y[i-1] += Y[i];
    }

    vector<ll> ans(N + 1,0ll);

    for (int i = 1; i < C.size(); i++) {
        ans[mp[C[i]]] = Y[i] * (C[i] - C[i - 1]) + X[i];
    }

    rep(i,0,N){
        cout << ans[i+1] << endl;
    }


    return 0;
}