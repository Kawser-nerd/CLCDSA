#ifdef ssu1
#define _GLIBCXX_DEBUG
#define _DEBUG_ 1
#else
#define _DEBUG_ 0
#endif

#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <bitset>
#include <sstream>

using namespace std;

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define X first
#define Y second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define db(x) if(_DEBUG_){ cout << __FUNCTION__ << "(" << __LINE__ << "): " << #x << " = " << x << endl; }
#define dbi(x, y) if(_DEBUG_){ cout << __FUNCTION__ << "(" << __LINE__ << "): [" << #x << "] ~ [" << #y << "]\n"; for(typeof(x) i = x; i != y; ++i) { cout << *(i) << " "; } cout << endl; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9) + 7;
const ld PI = acosl(ld(-1));
const ld EPS = 1e-9;

const int N = 110;

int n, m;
vector<int> g[N];
string s[N];

inline bool cmpS(int i, int j) {
    return s[i] < s[j];
}

vector<int> st;
string res;

int cused;
int used[N];
bool dead[N];
bool inAns[N];

void dfs(int v) {
    if (used[v] == cused || dead[v])
        return;
    used[v] = cused;
    forn(i, sz(g[v]))
        dfs(g[v][i]);    
}

bool checkDfs() {
    forn(v, n)
        if (!dead[v] && used[v] != cused)
            return false;
    return true;
}

int main(){
    #ifdef ssu1
    assert(freopen("input.txt", "r", stdin));
    #endif

    int tests;
    cin >> tests;
    
    forn(test, tests) {
        cin >> n >> m;
        
        forn(i, n) {
            g[i].clear();
            dead[i] = false;
            inAns[i] = false;
            
            cin >> s[i];
        }
        
        forn(i, m) {
            int v, u;
            cin >> v >> u;
            v--; u--;
            
            g[v].pb(u);
            g[u].pb(v);
        }
        
        int root = (int) (min_element(s, s + n) - s);
        
        st.pb(root);        
        inAns[root] = true;
        res = s[root];
        
        forn(qqq, n - 1) {
            int md = sz(st);
            while (md > 0) {
                md--;
                dead[st[md]] = true;
                
                cused++;
                dfs(root);
                if (!checkDfs()) {
                    dead[st[md]] = false;
                    md++;
                    break;
                }                
            }
            
            for (int i = md; i < sz(st); ++i)
                dead[st[i]] = false;
                
            
            string curMin = "A";
            int u = -1, v = -1;
                                    
            for (int si = sz(st) - 1; si >= md - 1 && si >= 0; --si) {
                int c = st[si];
                forn(i, sz(g[c])) {
                    int nx = g[c][i];
                    if (!inAns[nx] && s[nx] < curMin) {
                        curMin = s[nx];
                        v = c;
                        u = nx;
                    }
                }
            }
            
            assert(v != -1);
            
            while (st.back() != v) {
                dead[st.back()] = true;
                st.pop_back();
            }
            
            st.pb(u);
            inAns[u] = true;
            res.insert(res.end(), all(s[u]));
        }
                
        printf("Case #%d: %s\n", test + 1, res.c_str());
    }

    return 0;
}


