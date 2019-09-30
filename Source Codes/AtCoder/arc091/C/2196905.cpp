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

    ll N, A, B;
    cin >> N >> A >> B;

    if (!(A + B - 1 <= N && N <= A * B)) {
        cout << -1 << endl;
        return 0;
    }
    if (A == 1) {
        vector<int> v(N);
        rep(i, 0, N) {
            v[i] = i + 1;
        }
        reverse(all(v));
        for (auto e : v) {
            cout << e << " ";
        }

    } else if (B == 1) {
        vector<int> v(N);
        rep(i, 0, N) {
            v[i] = i + 1;
        }
        for (auto e : v) {
            cout << e << " ";
        }
//    } else if (B == 2) {
//        vector<vector<int> > vv(B);
//        vv.front().resize(A);
//        vv.back().resize(N - A - (N - A) / (B - 1) * (B - 2));
//        rep(i, 1, vv.size() - 1) {
//            vv[i].resize((N - A) / (B - 1));
//        }
//        int cnt = 0;
//        for (auto it = vv.rbegin(); it != vv.rend(); it++) {
//            rep(i, 0, it->size()) {
//                (*it)[i] = ++cnt;
//            }
//        }
//        for (auto e : vv) {
//            for (auto f : e) {
//                cout << f << " ";
//            }
//        }
    } else {
        vector<vector<int> > vv(B);
        vector<int> sizes(B,1);
        sizes[0] = A;
        int sumsi = (B-1) + A;
        rep(i,1,B){
            int diff = min(N-sumsi,A-sizes[i]);
            sumsi += diff;
            sizes[i] += diff;
        }


//        vv.front().resize(A);
//        vv.back().resize(N - A - (N - A) / (B - 1) * (B - 2));
//        rep(i, 1, vv.size() - 1) {
//            vv[i].resize((N - A) / (B - 1));
//        }
        rep(i,0,vv.size()){
            vv[i].resize(sizes[i]);
        }
        int cnt = 0;
        for (auto it = vv.rbegin(); it != vv.rend(); it++) {
            rep(i, 0, it->size()) {
                (*it)[i] = ++cnt;
            }
        }
        for (auto e : vv) {
            for (auto f : e) {
                cout << f << " ";
            }
        }
    }
    cout << endl;


    return 0;
}