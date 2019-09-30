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
#include <cstring>
#include <unordered_map>

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
class Solve {
public:
    int N;
    vector<ll> S;
    vector<ll> primes;

    void input() {
        cin >> N;
        S.resize(N);
        rep(i, 0, N) cin >> S[i];


        vector<ll> pf(3000, true);
        pf[0] = pf[1] = false;
        for (int i = 2; i < pf.size(); ++i) {
            if (pf[i]) {
                for (int j = i * 2; j < pf.size(); j += 2) {
                    pf[j] = false;
                }
            }
        }
        for (int i = 0; i < pf.size(); ++i) {
            if (pf[i]) primes.push_back(i);
        }


    }

    void solve() {
        input();

//        unordered_map<ll, int> mp;
        map<ll, int> mp;
        for (int i = 0; i < N; ++i) {
            ll tmp = S[i];
            for (auto p : primes) {
                ll p3 = p * p * p;
                while (tmp % p3 == 0) tmp /= p3;
            }
            mp[tmp]++;
        }

        //debug

        int ans = 0;
        set<ll> checked;

        for (const auto &e : mp) {
            ll num = e.first;
            ll par = 1ll;
            if (num == 1) {
                ans++;
                continue;
            }

            for (auto p : primes) {
                if (num % (p * p) == 0) {
                    num /= (p * p);
                    par *= p;
                } else if (num % p == 0) {
                    num /= p;
                    par *= (p * p);
                }
            }

            //num = 1 or n^2 or n
            if (num == 1) {
                if (checked.count(e.first) + checked.count(par) == 0) {
                    if (mp.count(par) == 0) {
                        int add = e.second;
                        ans += add;
                        checked.insert(e.first);
                    } else {
                        int add = max(e.second, mp[par]);
                        ans += add;
                        checked.insert(e.first);
                        checked.insert(par);
                    }
                }
                continue;
            }

            ll snum = (ll) round(sqrt(num));

            if (snum * snum == num) {
                // n^2
                par *= snum;
                if (checked.count(e.first) + checked.count(par) == 0) {
                    if (mp.count(par) == 0) {
                        int add = e.second;
                        ans += add;
                        checked.insert(e.first);
                    } else {
                        int add = max(e.second, mp[par]);
                        ans += add;
                        checked.insert(e.first);
                        checked.insert(par);
                    }
                }
                continue;
            }

            //num??????
            if (num >= 100000) {
                //?????????
                ans += e.second;
                continue;
            } else {
                par *= (num * num);
                if (checked.count(e.first) + checked.count(par) == 0) {
                    if (mp.count(par) == 0) {
                        int add = e.second;
                        ans += add;
                        checked.insert(e.first);
                    } else {
                        int add = max(e.second, mp[par]);
                        ans += add;
                        checked.insert(e.first);
                        checked.insert(par);
                    }
                }
                continue;
            }
        }

        cout << ans << endl;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}