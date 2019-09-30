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

vector<vector<int> > G;//??


ll rec(int v) {
    if (G[v].size() == 0) return 0;

    vector<ll> child;
    for (auto e : G[v]) {
        child.push_back(rec(e));
    }

    sort(child.rbegin(),child.rend());
    for (int i = 0; i < child.size(); ++i) {
        child[i] += i + 1;
    }
    sort(all(child));
    return child.back();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    G.resize(N + 1, vector<int>());

    for (int i = 2; i <= N; ++i) {
        int a;
        cin >> a;
        G[a].push_back(i);
    }

    cout << rec(1) << endl;

    return 0;
}