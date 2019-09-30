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

    ll X;
    cin >> X;
    int K;
    cin >> K;
    vector<ll> r(K);
    r.push_back(0);
    rep(i, 0, K) cin >> r[i + 1];

    //Cr[i]????
    vector<ll> Cr(K + 1);
    for (int i = 0; i < K; i++) {
        if (i % 2 == 0) {
            Cr[i + 1] = max(0LL, Cr[i] - (r[i + 1] - r[i]));
        } else {
            Cr[i + 1] = min(X, Cr[i] + (r[i + 1] - r[i]));
        }
    }

    //BEr[i],ENr[i]????
    vector<ll> BEr(K + 1), ENr(K + 1);
    BEr[0] = 0ll;
    ENr[0] = X;
    for (int i = 0; i < K; i++) {
//        if (i % 2 == 0 && Cr[i] - (r[i + 1] - r[i]) < 0) {
//            BEr[i + 1] = max((r[i + 1] - r[i]) - Cr[i], BEr[i]);
//            if(BEr[i+1] > X) BEr[i] = X;
//        } else {
//            BEr[i + 1] = BEr[i];
//        }
//        if (i % 2 == 1 && Cr[i] + (r[i + 1] - r[i]) + ENr[i] > X) {
//            ll tmp = (ENr[i] - BEr[i]) + Cr[i] + (r[i + 1] - r[i]);
//            ENr[i + 1] = min(2 * X - tmp, ENr[i]);
//            if(ENr[i + 1] < 0) ENr[i] = 0;
//        } else {
//            ENr[i + 1] = ENr[i];
//        }

        if (i % 2 == 0) {
            ENr[i + 1] = ENr[i];
            if (Cr[i] - (r[i + 1] - r[i]) < 0) {
//                BEr[i + 1] = max((r[i + 1] - r[i]) - Cr[i], BEr[i]);
//                if (BEr[i + 1] > ENr[i + 1]) BEr[i + 1] = X;
                ll inc = (r[i + 1] - r[i]) - Cr[i];
                BEr[i + 1] = min(BEr[i] + inc, ENr[i + 1]);
            } else {
                BEr[i + 1] = BEr[i];
            }
        } else {
            BEr[i + 1] = BEr[i];
            if (Cr[i] + (r[i + 1] - r[i]) + ENr[i] - BEr[i] > X) {
                ll dec = (ENr[i] - BEr[i]) + Cr[i] + (r[i + 1] - r[i]) - X;
//                ENr[i + 1] = min(2 * X - tmp, ENr[i]);
                ENr[i + 1] = max(ENr[i] - dec,BEr[i + 1]);
//                if (ENr[i + 1] < 0) ENr[i] = 0;
//                ENr[i + 1] = max(ENr[i + 1], BEr[i + 1]);
            } else {
                ENr[i + 1] = ENr[i];
            }
        }
    }

//    for (int i = 0; i < K; i++) {
//        if (i % 2 == 1 && Cr[i] + (r[i + 1] - r[i]) + ENr[i] > X) {
//            ll tmp = (ENr[i] - BEr[i]) + Cr[i] + (r[i + 1] - r[i]);
//            ENr[i + 1] = min(2 * X - tmp, ENr[i]);
//            if(ENr[i + 1] < 0) ENr[i] = 0;
//        } else {
//            ENr[i + 1] = ENr[i];
//        }
//    }


    int Q;
    cin >> Q;
    while (Q--) {
        ll t, a = 0;
        cin >> t >> a;
        ll A0 = a;

        int tpoint = upper_bound(all(r), t) - r.begin() - 1;
        ll BEt = BEr[tpoint];
        ll ENt = ENr[tpoint];
        ll Ct;

        if (tpoint % 2 == 0) {
            if (Cr[tpoint] - (t - r[tpoint]) < 0) {
//                BEt = max(BEt, (t - (r[tpoint] - r[tpoint])));
//                BEt = max(BEt, (t - r[tpoint]) - Cr[tpoint]);
                ll inc = (t - r[tpoint]) - Cr[tpoint];
                BEt = min(BEr[tpoint] + inc, ENr[tpoint]);
            }
            Ct = max(0LL, Cr[tpoint] - (t - r[tpoint]));
        } else {
            if (Cr[tpoint] + (t - r[tpoint]) + ENr[tpoint] - BEr[tpoint] > X) {
//                ENt = min(ENt, X - Cr[tpoint] - (t - r[tpoint]));
//                ENt = min(ENt, Cr[tpoint] + (t - r[tpoint]));
//                ll tmp = (ENr[tpoint] - BEr[tpoint]) + Cr[tpoint] + (t - r[tpoint]);
                ll dec = Cr[tpoint] + (t - r[tpoint]) + ENr[tpoint] - BEr[tpoint] - X;
                ENt = max(ENr[tpoint] - dec, BEr[tpoint]);
            }
            Ct = min(X, Cr[tpoint] + (t - r[tpoint]));
        }
        ll At;
        if (A0 < BEt) {
            At = Ct;
        } else if (ENt < A0) {
            At = Ct + (ENt - BEt);
        } else {
            At = Ct + (A0 - BEt);
        }

        cout << At << endl;
    }


    return 0;
}