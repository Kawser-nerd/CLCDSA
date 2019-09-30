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
    vector<int> A(N + 5), B(N + 5);
    rep(i, 0, N) cin >> A[i];

    rep(i, 1, N) {
        B[i] = A[i] - A[i - 1];
    }
//    rep(i, 2, N) {
//        if (B[i] == 0) {
//            B[i] = B[i - 1];
//        }
//    }
//    for (int i = N - 2; i >= 1; i--) {
//        if (B[i] == 0) {
//            B[i] = B[i + 1];
//        }
//    }
    int mode = 0;
    int ans = 1;
    rep(i, 1, N) {
        if (mode == 0) {
//            ans++;
            if (B[i] > 0) {
                mode = 1;
            } else if (B[i] < 0) {
                mode = -1;
            }
        } else if (mode == 1) {
            if (B[i] < 0) {
                ans++;
                mode = 0;
            }
        } else if (mode == -1) {
            if (B[i] > 0) {
                ans++;
                mode = 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}