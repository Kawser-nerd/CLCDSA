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
typedef long long ll;
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

pair<ll, ll> get_inter(ll s1, ll e1, ll s2, ll e2){
    if(s1 > s2) return get_inter(s2, e2, s1, e1);
    else if(e1 <= s2) return P(0,0);
    else return P(s2, min(e1, e2));
}

int main(){
    ll N, M; cin >> N >> M;
    map<ll, ll> m;
    REP(i, M){
        ll a, b; cin >> a >> b; m[a] = (m[a] <= 0) ? b : min(m[a], b);
    }
    map<ll, ll> m_is;
    FORMAP(it, m){
        if(it == m.begin()){
            m_is[m.begin()->first] = m.begin()->second;
            continue;
        }
        auto it_t = m_is.upper_bound(it->first);
        auto it_p = it_t;
        if(m_is.size() == 1){
            it_p = m_is.begin(); it_t = m_is.begin();
        }
        else{
            if(it_t == m_is.begin())
                it_p++;
            else if(it_t == m_is.end()){
                it_t = m_is.end()--; it_p = it_t--;
            }
          	else{
              it_p = it_t--;
            }
        }
        
        auto inter_t = get_inter(it->first, it->second, it_t->first, it_t->second);
        auto inter_p = get_inter(it->first, it->second, it_p->first, it_p->second);
        if(inter_t != PL(0ll,0ll)){
            m_is.erase(it_t); m_is[inter_t.first] = inter_t.second;
        }
        else if(inter_p != PL(0ll, 0ll)){
            m_is.erase(it_t); m_is[inter_p.first] = inter_p.second;
        }
        else{
            m_is[it->first] = it->second;
        }
    }
    cout << m_is.size() << endstr;
    return 0;
}