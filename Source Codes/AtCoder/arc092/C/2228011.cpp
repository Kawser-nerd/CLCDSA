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
    ll maxa = -INF;
    int max_k = -1;
    rep(i, 0, N) {
        cin >> a[i];
        if (maxa < a[i]) {
            maxa = a[i];
            max_k = i;
        }
    }

    //????????
    if (maxa < 0) {
        vector<int> ope;
        for (int i = N - 1; max_k != i; i--) {
            ope.push_back(i + 1);
        }
        for (int i = 0; i <= max_k - 1; i++) {
            ope.push_back(1);
        }
        cout << maxa << endl;
        cout << ope.size() << endl;
        rep(i, 0, ope.size()) {
            cout << ope[i] << endl;
        }
        return 0;
    }

    vector<int> ope;
//    if (a[0] < 0) {
//        a.erase(a.begin());
//        ope.push_back(1);
//    }
    while (a[0] < 0) {
        a.erase(a.begin());
        ope.push_back(1);
    }

    ll odd = 0LL, even = 0LL;
    rep(i, 0, a.size()) {
        if (i % 2 == 0) {
            even += 1LL * max(a[i], 0ll);
        } else {
            odd += 1LL * max(a[i], 0ll);
        }
    }
    if (even > odd) {

        int size = a.size();
        int db = size - 1;
//        if (db % 2 == 1) {
//            db--;
//        }
        for (int i = db; i >= 0; i--) {
            if (a[i] < 0 && i % 2 == 0) {
                if (i == 0 || i == size - 1) size--;
                else size -= 2;
                ope.push_back(i + 1);
            }
        }
        db = size - 1;
        for (int i = db; i >= 0; i--) {
            if (i % 2 == 1) {
                ope.push_back(i + 1);
            }
        }

        cout << even << endl;
        cout << ope.size() << endl;
        rep(i, 0, ope.size()) {
            cout << ope[i] << endl;
        }

    } else {
        //?????

        int size = a.size();
        int db = size - 1;
//        if (db % 2 == 0) {
//            db--;
//        }
        for (int i = db; i >= 0; i--) {
            if (a[i] < 0 && i % 2 == 1) {
                if (i == 0 || i == size - 1)size--;
                else size -= 2;
                ope.push_back(i + 1);
            }

        }
        db = size - 1;
        for (int i = db; i >= 0; i--) {
            if (i % 2 == 0) {
                ope.push_back(i + 1);
            }
        }

        cout << odd << endl;
        cout << ope.size() << endl;
        rep(i, 0, ope.size()) {
            cout << ope[i] << endl;
        }

    }


    return 0;
}