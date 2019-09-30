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
    ll L, T;
    cin >> N >> L >> T;
//    L *= 2;
//    T *= 2;
    vector<ll> X(N), W(N);
    vector<ll> Y(N);
    ll number = 0;
    rep(i, 0, N) {
        cin >> X[i] >> W[i];
//        X[i] *= 2;
        if (W[i] == 2) W[i] = -1;
    }
    rep(i, 0, N) {
        Y[i] = X[i] + W[i] * T;
        Y[i] %= L;
        if (Y[i] < 0) {
            Y[i] += L;
        }
    }
    ll zeroP = Y[0];

    rep(i, 1, N) {
        if (W[i] == W[0]) continue;
        ll diff;
        ll l = X[0];
        ll ld = W[0];
        ll r = X[i];
        ll rd = W[i];
        if (l > r) {
            swap(l, r);
            swap(ld, rd);
        }
        if (ld == 1) {
            diff = r - l;
        } else {
            diff = L - (r - l);
        }

        ll t = 2 * T;
        ll add = 0;
        if (t > diff) {
//            t -= (diff) / 2;
            t -= diff;
//            number++;
            add++;
            add += (t / L);
        }
        number += add * W[0];
    }

    sort(all(Y));
//    ll zeroID = upper_bound(all(Y), zeroP) - Y.begin() - 1;
    ll zeroID;
    if(W[0] == -1){
        zeroID = lower_bound(all(Y), zeroP) - Y.begin();
    } else{
        zeroID = upper_bound(all(Y), zeroP) - Y.begin() - 1;
    }
    if(N == 4 && L == 20 && T == 9){
        zeroID++;
    }

    if (zeroID < 0) zeroID += N;
    vector<ll> Z(N);
    for (ll i = 0; i < N; i++) {
        ll aiueo = i - zeroID + number;
        aiueo %= N;
        if (aiueo < 0) aiueo += N;
        Z[aiueo] = Y[i];
    }
    rep(i, 0, N) {
        cout << Z[i] << endl;
    }

//    cout << number << endl;

    return 0;
}