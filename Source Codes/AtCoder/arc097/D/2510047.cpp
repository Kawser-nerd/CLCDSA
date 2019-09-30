#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<double> VD;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const int N = 1e5;
set<int> e[N];
int c[N], dead[N];

int main() {
    int n;
    cin >> n;
    REP(i,n-1){
        int u = in() - 1, v = in() - 1;
        e[u].insert(v);
        e[v].insert(u);
    }
    string s;
    cin >> s;
    REP(i,n) if (s[i] == 'W') c[i] = 1;

    queue<int> que;
    REP(i,n){
        if (e[i].size() <= 1) que.push(i);
    }

    int m = n;

    while (!que.empty()){
        int x = que.front();
        que.pop();
        if (c[x] == 0){
            m--;
            dead[x] = 1;
            for (int y : e[x]){
                e[y].erase(x);
                if (e[y].size() == 1) que.push(y);
            }
            e[x].clear();
        }
    }

    if (m <= 1){
        cout << m << endl;
        return 0;
    }

    int ans = 2 * (m - 1);
    REP(i,n){
        if (dead[i]) continue;
        ans += c[i] ^ (e[i].size() % 2);
    }

    VI a(n);
    REP(i,n){
        if (dead[i]) continue;
        if (c[i] ^ (e[i].size() % 2)) a[i] = 1;
    }

    int root = -1;
    REP(i,n){
        if (!dead[i]){
            root = i;
            break;
        }
    }

    VI cnt(n);
    function<void (int, int)> dfs = [&](int now, int past){
        for (int next : e[now]){
            if (dead[next] || next == past) continue;
            cnt[next] = cnt[now] + a[next];
            dfs(next, now);
        }
    };

    cnt[root] = a[root];
    dfs(root, -1);

    int ma = -1;
    REP(i,n){
        if (!dead[i] && cnt[i] > ma){
            root = i;
            ma = cnt[i];
        }
    }

    cnt.assign(n, 0);
    cnt[root] = a[root];
    dfs(root, -1);

    ans -= 2 * *max_element(ALL(cnt));
    cout << ans << endl;

    return 0;
}