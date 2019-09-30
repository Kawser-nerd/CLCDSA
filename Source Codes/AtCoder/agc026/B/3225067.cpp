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
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//????????
void jikken() {
    int la = 0, ra = 114;
//    int b = 10, c = 8, d = 12;
    int tapi = 2;
    int b = 7 * tapi, c = 6 * tapi, d = 98 * tapi;
    for (int i = la; i < ra; ++i) {
        int tmp = i;
        while (tmp > c) tmp -= b;
        bool flag = true;
        rep(j, 0, 1000) {
            if (tmp <= c) tmp += d;
            if (tmp < b) {
                flag = false;
                break;
            }
            tmp -= b;
        }
        if (flag) {
            cout << i << " : o" << endl;
        } else {
            cout << i << " : x" << endl;
        }
    }
}

bool cmp3(ll a, ll b, ll c) {
    return a < b && b < c;
}

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (a % b == 0) return b;
    return gcd(b, a % b);

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

//    jikken();
    int T;
    cin >> T;
    while (T--) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        if (A < B) {
            cout << "No" << endl;
            continue;
        }
        if (A > C) {
            A -= (A - C) / B * B;
        }
        while (A > C) {
            A -= B;
        }
        if (A < 0) {
            cout << "No" << endl;
        } else if (D > B) {

//            ll d = D - B;
//            if(d <= B - 1 - C){
//                cout << "No" << endl;
//            }else if (cmp3(C % d, A % d, B % d)) {
//                cout << "No" << endl;
//            } else {
//                cout << "Yes" << endl;
//            }
            ll g = gcd(B, D);
            ll d = D - B;
            if (g <= B - 1 - C) {
                cout << "No" << endl;
            } else if (B - 1 - C <= 0) {
                cout << "Yes" << endl;
            } else if (C % g < B % g) {
                if (cmp3(C % g, A % g, B % g)) {
                    cout << "No" << endl;
                } else {
                    cout << "Yes" << endl;
                }
            } else if (C % g > B % g) {
                if (cmp3(B % g - 1, A % g, C % g + g + 1)) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            } else {
                if (B % g == A % g) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        } else if (D < B) {
            cout << "No" << endl;
        } else {
            if (cmp3(C, A, D)) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }

    return 0;
}