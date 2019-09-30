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
    int N;
    vector<string> from;
    vector<double> weight;
    vector<string> to;

    vector<string> word;
    map<string, int> stoid;

    vector<vector<pair<int, double>>> G;
    vector<bool> used;

    void input() {
        cin >> N;
        rep(i, 0, N) {
            string f, t;
            int w;
            cin >> f >> w >> t;
            from.push_back(f);
            weight.push_back(w);
            to.push_back(t);
        }

        for (int i = 0; i < N; ++i) {
            if (stoid.count(from[i]) == 0) {
                stoid[from[i]] = (int) word.size();
                word.push_back(from[i]);
            }
            if (stoid.count(to[i]) == 0) {
                stoid[to[i]] = (int) word.size();
                word.push_back(to[i]);
            }
        }

        G.resize(word.size());
        for (int i = 0; i < N; ++i) {
            G[stoid[from[i]]].emplace_back(stoid[to[i]], weight[i]);
            G[stoid[to[i]]].emplace_back(stoid[from[i]], 1.0 / weight[i]);
        }
    }

    pair<string, double> dfs(int v) {
        used[v] = true;
//        if (G[v].size() == 0) {
//            return make_pair(word[v], 1.0);
//        }
        pair<string, double> ret(word[v], 1.0);
        for (auto e : G[v]) {
            if (used[e.first]) continue;

            pair<string, double> tmp = dfs(e.first);
            double cost = tmp.second * e.second;
            if (ret.second < cost) {
                ret = make_pair(tmp.first, cost);
            }
        }

        return ret;
    }


    void solve() {
        input();

        string s = "";
        string t = "";
        double val = -1;

        for (int i = 0; i < word.size(); ++i) {
            used.assign(word.size(), false);
            pair<string, double> tmp = dfs(i);
            if (tmp.second > val) {
                s = word[i];
                t = tmp.first;
                val = tmp.second;
            }
        }

        int ans = (int) round(val + 0.1);

        cout << 1 << s << "=" << ans << t << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Solve().solve();


    return 0;
}