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

//    if(true){
//        vector<int> tes(10);
//        cout << tes.end() - tes.begin() << endl;
//        return 0;
//    }

    int N;
    ll L;
    cin >> N;
    vector<ll> x(N + 1);
    rep(i, 0, N) {
        cin >> x[i];
    }
    x[N] = INF;
    cin >> L;

    vector<vector<int> > v(N + 5, vector<int>(18, INF));
    int X = INF;

    rep(i, 0, N) {
        auto it = upper_bound(all(x), L + x[i]);
//        if(it == x.end()){
//            v[i][0] = X;
//        }else{
//            v[i][0] = it - 1 - x.begin();
//        }

        int next = it - 1 - x.begin();
        if (next == i) v[i][0] = X;
        else v[i][0] = next;
    }

    for (int k = 1; k < v[0].size(); k++) {
        for (int i = 0; i < N; i++) {
            if (v[i][k - 1] != X)
                v[i][k] = v[v[i][k - 1]][k - 1];
        }
    }


    int Q;
    cin >> Q;
    rep(i, 0, Q) {
        int a, b;
        cin >> a >> b;
        if (b < a) swap(a, b);
        a--;
        b--;

//        ll ans = 0;
//        for (int j = v[0].size() - 1; j >= 0; j--) {
//            if (v[cur][j] > b) {
//
//            } else {
//                ans += (1 << j);
//                cur = v[cur][j];
//            }
//        }
//        cout << ans << endl;
        int ng = 0;
        int ok = N + 5;

        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            int res = mid;
            int cur = a;

            int k = 0;
            while (res > 0) {
                if (res & 1) {
                    if (cur != INF)
                        cur = v[cur][k];
                }
                res >>= 1;
                k++;
            }
            if(cur >= b){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        cout << ok << endl;


    }


    return 0;
}