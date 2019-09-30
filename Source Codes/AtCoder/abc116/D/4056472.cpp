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
class Solve {
public:
    ll N, K;
    vector<pair<ll, ll>> td;

    void input() {

    }


    void solve() {
        input();
        cin >> N >> K;

        vector<ll> t(N), d(N);
        rep(i, 0, N) {
            cin >> t[i] >> d[i];
        }
        for (int i = 0; i < N; ++i) {
            td.emplace_back(t[i], d[i]);
        }
        sort(all(td), [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.second > b.second;
        });


        vector<vector<ll>> table(N);
        for (int i = 0; i < td.size(); ++i) {
            table[td[i].first - 1].push_back(td[i].second);
        }

        //K???
        ll ans = 0ll;
        ll kouho = 0ll;
        set<ll> used;
        vector<vector<ll> > usedtable(N);
        vector<ll> tapu;
        for (int i = 0; i < K; ++i) {
            used.insert(td[i].first - 1);
            usedtable[td[i].first - 1].push_back(td[i].second);
            kouho += td[i].second;
        }
        for (int i = 0; i < N; ++i) {
            sort(all(usedtable[i]));
            for (int j = 0; j + 1 < usedtable[i].size(); ++j) {
                tapu.push_back(usedtable[i][j]);
            }
        }
        kouho += used.size() * used.size();
        ans = kouho;
        sort(all(tapu));


        vector<ll> tapi;
        for (int i = 0; i < N; ++i) {
            if (used.count(i) == 0 && table[i].size() > 0) {
                sort(all(table[i]));
                tapi.push_back(table[i].back());
            }
        }
        sort(tapi.rbegin(), tapi.rend());

        ll shu = used.size();
        for (int i = 0; i < tapu.size() && i < tapi.size(); ++i) {
            kouho -= shu * shu;
            shu++;
            kouho += shu * shu;
            kouho += tapi[i];
            kouho -= tapu[i];
            chmax(ans, kouho);
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