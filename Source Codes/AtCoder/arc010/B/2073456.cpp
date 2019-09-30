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
#define INF (1 << 30)
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//????????
int mon[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mons[12] = {};

int conv(string s) {
    string a, b;
    bool flag = false;
    rep(i, 0, s.size()) {
        if (s[i] == '/') {
            flag = true;
            continue;
        }
        if (!flag) {
            a += s[i];
        } else {
            b += s[i];
        }
    }
    if (stoi(a) == 1) return stoi(b);
    return mons[stoi(a) - 1] + stoi(b);


}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    rep(i, 1, 12) {
        mons[i] = mons[i - 1] + mon[i - 1];
    }
    int N;
    cin >> N;
    int hol[370] = {};
    rep(i, 1, 367) {
        if (i % 7 == 1 || i % 7 == 0) {
            hol[i]++;
        }
    }

    rep(i, 0, N) {
        string s;
        cin >> s;
        hol[conv(s)]++;
//        cout << conv(s) << endl;
    }
    for (int i = 1; i <= 366; i++) {
        if (hol[i] > 1) {
            hol[i + 1] += (hol[i] - 1);
            hol[i] = 1;
        }
    }
    int max_se = 0;
    int se = 0;
    for (int i = 1; i <= 366; i++) {
        if (hol[i] == 0) {
//            max_se = max(se,max_se);
            se = 0;
        } else {
            se++;
            max_se = max(se, max_se);
        }
    }
    cout << max_se << endl;

//    cout << conv("1/31") << endl;
//    cout << conv("2/1") << endl;

    return 0;
}