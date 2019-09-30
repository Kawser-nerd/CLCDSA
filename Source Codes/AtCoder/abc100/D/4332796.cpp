#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string>
#include <numeric>
#include <queue>
#include <deque>
using namespace std;
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> vp;
typedef vector<PL> vpl;
typedef vector<vector<P>> vvp;
const int INF = 1001001001;
const ll LINF = 1e18;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define REP(i, n) for(ll i = 0; i < n; i++)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)
#define ff first
#define ss second

template <typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b%a, a);
}
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

bool p_comp_fs(const P p1, const P p2){ return p1.first < p2.first;};
bool p_comp_fg(const P p1, const P p2){ return p1.first > p2.first;};
bool p_comp_ss(const P p1, const P p2){ return p1.second < p2.second;};
bool p_comp_sg(const P p1, const P p2){ return p1.second > p2.second;};
template <typename T>
vector<T> uniquen(vector<T> vec){
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}


int main(){
    ll N, M; cin >> N >> M; vl xs(N, 0), ys(N, 0), zs(N, 0);
    REP(i, N) cin >> xs[i] >> ys[i] >> zs[i];
    ll ret = 0;
    REP(i, 8){
        vl vals(N, 0);
        ll sx = (i >> 0 & 1) ? 1 : -1;
        ll sy = (i >> 1 & 1) ? 1 : -1;
        ll sz = (i >> 2 & 1) ? 1 : -1;
        REP(i, N) vals[i] = sx * xs[i] + sy * ys[i] + sz * zs[i];
        sort(vals.begin(), vals.end(), greater<ll>());
        ll tmp = 0;
        REP(i, M) tmp += vals[M-i-1];
        ret = max(ret, tmp);
    }
    cout << ret << endstr;
    return 0;
}