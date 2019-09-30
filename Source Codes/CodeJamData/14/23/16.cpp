#include <iostream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <string>
#include <deque>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>

#include <algorithm>
#include <numeric>

#define foreach(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define sqr(x) ((x) * (x))
#define len(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define endl '\n'

#ifdef CUTEBMAING
#include "cutedebug.h"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(x) 42
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef unsigned long long lint;
typedef long double ld;

const int inf = ((1 << 30) - 1);
const int64 linf = ((1ll << 62) - 1);
const int N = 51;

#define index _index

int n, m, index;
vector<int> g[N];
string s[N];
string ans = "";
int u[N];
bool uu[N];

inline bool cmp(int a, int b){
    return s[a] < s[b];
}

void dfs(int v){
    if (u[v] == 2 || uu[v])
        return ;
    uu[v] = 1;
    for (int i = 0; i < len(g[v]); i++)
        dfs(g[v][i]);
}

bool canExit(){
    fill_n(uu, n, false);
    dfs(index);
    bool flag = true;
    for (int i = 0; i < n; i++)
        if (!uu[i] && u[i] != 2){
            flag = false;
            break;
        }
    return flag;
}

vector<int> path;

int countExit(){
    for (int i = len(path) - 1; i >= 0; i--){
        u[path[i]] = 2;
        if (!canExit()){
            for (int i = 0; i < len(path); i++)
                u[path[i]] = 1;
            return i;
        }
    }
    return 0;
}

void go(int v){
    path.pb(v);
    ans += s[v];
    u[v] = 1;
    for (int i = 0; i < len(g[v]); i++){
        if (u[g[v][i]] != 0)
            continue;
        int size = countExit();
        bool flag = true;
        string curS = s[g[v][i]];
        for (int t = size; t < len(path); t++){
            int j = path[t];
            if (u[j] == 1){
                for (int k = 0; k < len(g[j]); k++)
                    if (u[g[j][k]] == 0 && s[g[j][k]] < curS){
                        flag = false;
                        break;
                    }
                if (!flag)
                    break;
            }
        }
        if (!flag)
            break;
        go(g[v][i]);
    }
    u[v] = 2;
    path.pbk();
}

bool stcheck(const vector<int> &p){
    vector<int> path;
    path.pb(p[0]);
    for (int i = 1; i < n; i++){
        while (len(path) > 0 && find(all(g[path.back()]), p[i]) == g[path.back()].end())
            path.pbk();
        if (len(path) == 0)
            return false;
        path.pb(p[i]);
    }
    return true;
}

string stupid(){
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = i;
    string ans = "\255";
    do{
        if (!stcheck(p))
            continue;
        string curAns = "";
        for (int i = 0; i < n; i++)
            curAns += s[p[i]];
        ans = min(ans, curAns);
    }
    while (next_permutation(all(p)));
    return ans;
}

void solve(){
    cin >> n >> m;
    //eprintf("%d %d\n", n, m);
    fill_n(g, n, vector<int>());
    for (int i = 0; i < n; i++){
        cin >> s[i];
        //eprintf("%s\n", s[i].c_str());
    }
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v), g[v].pb(u);
        //eprintf("%d %d\n", u + 1, v + 1);
    }
    for (int i = 0; i < n; i++)
        sort(all(g[i]), cmp);
    index = min_element(s, s + n) - s;
    ans = "";
    fill_n(u, n, 0);
    path.clear();
    go(index);
    //string stup = stupid();
    //eprintf("Answer: %s; Stupid: %s\n", ans.c_str(), stup.c_str());
    //assert(ans == stup);
    cout << ans << endl;
}

int main(){
#if defined CUTEBMAING && !defined STRESS
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif
    int testCasesCount = 0;
    cin >> testCasesCount;
    for (int i = 1; i <= testCasesCount; i++){
        printf("Case #%d: ", i);
        double begin = clock();
        if (i == 9){
            i = 9;
        }
        solve();
        double end = clock();
        eprintf("Test %d: %.3lf seconds\n", i, (end - begin) / CLOCKS_PER_SEC);
    }
    return 0;
}
