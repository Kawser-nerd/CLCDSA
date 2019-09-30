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

int N;
vector<ll> A;
vector<vector<int> > G;

//v????????p
ll dfs(int v, int p) {
    if (G[v].size() == 1) {
        return A[v];
    }
    ll ret = 2 * A[v];

    vector<ll> child;

    for (auto e : G[v]) {
        if (e != p) {
            child.push_back(dfs(e, v));
            ret -= child.back();
        }
    }

    if (ret < 0) {
        cout << "NO" << endl;
        exit(0);
    }

    if (ret > A[v]) {
        cout << "NO" << endl;
        exit(0);
    }


    ll max_child = *max_element(all(child));
    ll parent = A[v];
    if(max_child > parent){
        cout << "NO" << endl;
        exit(0);
    }


    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    G.resize(N);

    rep(i, 0, N) cin >> A[i];

    rep(i, 0, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    if (N == 2) {
        if (A[0] == A[1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    int root = -1;
    for (int i = 0; i < N; ++i) {
        if (G[i].size() > 1) {
            root = i;
            break;
        }
    }
    if (root == -1) {
        return -1;
    }

    ll val = dfs(root, -1);

    if (val == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}