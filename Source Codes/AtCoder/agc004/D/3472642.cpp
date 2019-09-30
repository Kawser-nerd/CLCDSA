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
#include <cstdlib>

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
int N;
ll K;
int ans = 0;
vector<int> parent;
vector<vector<int> > G;


//??????????ans????????
int dfs(int n) {
    int max_child = 0;
    for (auto child : G[n]) {
        chmax(max_child, dfs(child));
    }

    int ret = max_child + 1;
    if(ret > K){
        exit(-1);
    }
    if (ret == K) {
        if (parent[n] != 0) ans++;
        ret = 0;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    G.resize(N);

    rep(i, 0, N) {
        int p;
        cin >> p;
        p--;
        if (i == 0) {
            if (p != 0)
                ans++;
            parent.push_back(0);
            continue;
        }
        parent.push_back(p);
        G[p].push_back(i);
    }

    dfs(0);
    cout << ans << endl;


    return 0;
}