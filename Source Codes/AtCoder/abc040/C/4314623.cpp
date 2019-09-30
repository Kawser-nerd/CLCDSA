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
    ll N; cin >> N;
    vl as(N+1, 0); REP(i, N) cin >> as[i+1];
    vl dp(N+1, 0);
    dp[1] = 0; dp[2] = abs(as[2] - as[1]);
    FOR(i,3,N+1){
        dp[i] = min(abs(as[i] - as[i-1]) + dp[i-1], abs(as[i] - as[i-2]) + dp[i-2]);
    }
    cout << dp[N] << endstr;
    return 0;
}