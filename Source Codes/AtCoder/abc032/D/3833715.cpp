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
    void input() {

    }

    //?????
    void half(int N, ll W, vector<ll> v, vector<ll> w) {
        if (N <= 15) {
            //???????
            ll ans = 0ll;
            for (int bit = 0; bit < 1 << N; ++bit) {
                ll value = 0ll;
                ll weight = 0ll;
                for (int i = 0; i < N; ++i) {
                    if (bit >> i & 1) {
                        value += v[i];
                        weight += w[i];
                    }
                }
                if (weight <= W) chmax(ans, value);
            }
            cout << ans << endl;
            return;
        }

        vector<ll> v1(v.begin(), v.begin() + 15);
        vector<ll> v2(v.begin() + 15, v.end());

        vector<ll> w1(w.begin(), w.begin() + 15);
        vector<ll> w2(w.begin() + 15, w.end());

        vector<pair<ll, ll>> part1, part2; //??max??????? , first: weight, second: value

        //part1
        for (int bit = 0; bit < 1 << v1.size(); ++bit) {
            ll value = 0ll;
            ll weight = 0ll;
            for (int i = 0; i < N; ++i) {
                if (bit >> i & 1) {
                    value += v1[i];
                    weight += w1[i];
                }
            }
            part1.push_back(make_pair(weight, value));
        }

        //part2
        for (int bit = 0; bit < 1 << v2.size(); ++bit) {
            ll value = 0ll;
            ll weight = 0ll;
            for (int i = 0; i < N; ++i) {
                if (bit >> i & 1) {
                    value += v2[i];
                    weight += w2[i];
                }
            }
            part2.push_back(make_pair(weight, value));
        }

        sort(all(part1));
        sort(all(part2));

        //??max?????
        for (int i = 0; i < part1.size() - 1; ++i) {
            part1[i + 1].second = max(part1[i].second, part1[i + 1].second);
        }
        for (int i = 0; i < part2.size() - 1; ++i) {
            part2[i + 1].second = max(part2[i].second, part2[i + 1].second);
        }

        vector<ll> part1w, part1v, part2w, part2v;
        for (auto e : part1) {
            part1w.push_back(e.first);
            part1v.push_back(e.second);
        }

        for (auto e : part2) {
            part2w.push_back(e.first);
            part2v.push_back(e.second);
        }

        //????????????????????????
        ll ans = 0ll;
        for (auto e : part1) {
            ll weight = e.first;
            ll value = e.second;

            ll rest = W - weight;
            if (rest < 0) continue;

            int pt = upper_bound(all(part2w), rest) - part2w.begin() - 1;
            ll tmp = value + part2v[pt];
            chmax(ans, tmp);
        }

        cout << ans << endl;


    }

    //dp[index][weight], ??????
    void dpw(int N, ll W, vector<ll> v, vector<ll> w) {
        vector<vector<ll> > dp(N + 1, vector<ll>(W + 1));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= W; ++j) {
                chmax(dp[i + 1][j], dp[i][j]);
                if (j + w[i] <= W) {
                    chmax(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
                }
            }
        }
        ll ans = 0ll;
        for (int i = 0; i <= W; ++i) chmax(ans, dp[N][i]);
        cout << ans << endl;
    }

    //dp[index][value], ?????????
    void dpv(int N, ll W, vector<ll> v, vector<ll> w) {
        ll SUMv = accumulate(all(v), 0ll);
        vector<vector<ll>> dp(N + 1, vector<ll>(SUMv, INFl));
        dp[0][0] = 0ll;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < SUMv; ++j) {
                chmin(dp[i + 1][j], dp[i][j]);
                chmin(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
            }
        }

        ll ans = 0ll;
        for (int i = 0; i < SUMv; ++i) {
            if (dp[N][i] <= W) {
                chmax(ans, i);
            }
        }
        cout << ans << endl;
    }

    void solve() {
        input();
        int N;
        ll W;
        cin >> N >> W;

        vector<ll> v(N), w(N);
        rep(i, 0, N) cin >> v[i] >> w[i];

//        half(N, W, v, w);

//        ll SUM = accumulate(all(w), 0ll);
//        dpw(N, min(SUM, W), v, w);

//        dpv(N, W, v, w);


        if (N <= 30) {
            half(N, W, v, w);
        } else if (*max_element(all(w)) <= 1000) {
            ll SUM = accumulate(all(w), 0ll);
            dpw(N, min(SUM, W), v, w);
        } else {
            dpv(N, W, v, w);
        }


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}