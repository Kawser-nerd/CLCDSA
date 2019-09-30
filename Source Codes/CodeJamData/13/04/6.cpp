//Coder: Balajiganapathi

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros

#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define fr(i,n)     re(i,0,n)
#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const int mx = 202;
const int kmx = 404;

int dp[(1 << 20) + 100];
int cnt[(1 << 20) + 100][mx];

int n;
int open[mx], cur[mx], done[mx], cover[mx], mark;
vi contains[mx], start;
vi req[kmx];

void calc(int mask) {
    ini(cur, 0);
    fr(i, sz(start)) ++cur[start[i]];
    fr(i, n) if(mask & (1 << i)) {
        --cur[open[i]];
        fr(j, sz(contains[i])) ++cur[contains[i][j]];
    }
}
int rem[mx], rcnt = n;
void calc_rem(int x) {
    fr(i, sz(contains[x])) --cur[contains[x][i]];
    ++cur[open[x]];
    //done[x] = 0;
}

void calc_add(int x) {
    fr(i, sz(contains[x])) ++cur[contains[x][i]];
    --cur[open[x]];
    //done[x] = 1;
}

void dfs(int x) {
    if(done[x] || cover[x] == mark) return;
    cover[x] = mark;
    
    fr(i, sz(contains[x])) {
        int key = contains[x][i];
        fr(j, sz(req[key])) dfs(req[key][j]);
    }
}

bool isOK(int pos) {
    ++mark;
    fr(i, rcnt) if(i != pos && cur[open[rem[i]]] > 0) dfs(rem[i]);
    fr(i, rcnt) if(i != pos && cover[rem[i]] != mark) return false;
    return true;
}

vi solve_greedy() {
    vi ret;
    vi empty;
    
    fr(i, n) rem[i] = i; rcnt = n;
    ini(cur, 0); ini(done, 0);
    fr(i, sz(start)) ++cur[start[i]];
    
    while(rcnt) {
        //if(!isOK()) return empty;
        int b = -1;
        fr(i, rcnt) if(cur[open[rem[i]]] > 0 && (b == -1 || rem[i] < rem[b])) {
            calc_add(rem[i]);
            if(isOK(i)) b = i;
            calc_rem(rem[i]);
        }
        //cerr << b << " " << rem[b] << endl;
        if(b == -1) return empty;
        calc_add(rem[b]);
        ret.pu(1 + rem[b]);
        done[rem[b]] = 1;
        --rcnt;
        swap(rem[b], rem[rcnt]);
    }
    assert(sz(ret) == n);
    return ret;    
}

vi solve_dp() {
    vi ret;
    vector<pi> order;
    fr(i, (1 << n)) {
        dp[i] = -1;
        order.pu(mp(__builtin_popcount(i), i));
    }
    sort(all(order));
    
    ini(cnt, 0);
    fr(i, sz(start)) ++cnt[0][start[i]];
    re(ii, 0, sz(order)) {
        int mask = order[ii].se;
        fr(i, n) if(mask & (1 << i)) {
            fr(j, mx) cnt[mask][j] = cnt[mask ^ (1 << i)][j];
            fr(j, sz(contains[i])) ++cnt[mask][contains[i][j]];
            --cnt[mask][open[i]];
            break;
        }
        /*
        cerr << mask << ": " << endl;
        fr(i, mx) if(cnt[mask][i]) cerr << i << " " << cnt[mask][i] << endl;
        cerr << sz(start) << "----------\n";
        * */
    }
    
    reverse(all(order));

    fr(ii, sz(order)) {
        int mask = order[ii].se;
        calc(mask);
        fr(i, mx) assert(cnt[mask][i] == cur[i]);
        bool ok = true;
        fr(i, mx) if(cnt[mask][i] < 0) ok = false;
        if(ok) {
            fr(i, n) if((mask & (1 << i)) == 0 && cnt[mask][open[i]] > 0) {
                if(dp[mask | (1 << i)] != -1) {
                    dp[mask] = i;
                    break;
                }
            }
            
            if(mask == (1 << n) - 1) dp[mask] = n;
        }
        //cerr << mask << " " << dp[mask] << endl;
    }
    
    if(dp[0] == -1) return ret;
    
    int mask = 0;
    while(mask != (1 << n) - 1) {
        ret.pu(dp[mask] + 1);
        mask |= (1 << dp[mask]);
    }
    
    assert(sz(ret) == n);
    
    return ret;
}

void printIt(vi ret) {
    cerr << "ANS: ";
    if(sz(ret)) {
        fprintf(stderr, "%d", ret[0]);
        re(i, 1, n) fprintf(stderr, " %d", ret[i]);
    } else fprintf(stderr, "IMPOSSIBLE");
    fprintf(stderr, "\n");
    cerr << "----------------\n";
}

int main() {
    //freopen("sample.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen("D-small-attempt0.in", "r", stdin); freopen("small0_test.txt", "w", stdout);
    freopen("D-large.in", "r", stdin); freopen("large.txt", "w", stdout);

    int _T;
    scanf("%d", &_T);
    for(int _t = 1; _t <= _T; ++_t) {
        int k;
        scanf("%d %d", &k, &n);
        start.clear(); fr(i, n) contains[i].clear();
        fr(i, kmx) req[i].clear();
        int x;
        while(k--) {
            scanf("%d", &x);
            start.pu(x);
        }
        
        fr(i, n) {
            scanf("%d %d", &open[i], &k);
            while(k--) {
                scanf("%d", &x);
                contains[i].pu(x);
            }
            req[open[i]].pu(i);
        }
        cerr << _t << endl;
        printf("Case #%d: ", _t);
        vi ret = solve_greedy();
        /*
        vi ans = solve_dp();
        if(ret != ans) {
            printIt(ret);
            printIt(ans);
        }
        assert(ret == ans);
        * */
        if(sz(ret)) {
            printf("%d", ret[0]);
            re(i, 1, n) printf(" %d", ret[i]);
        } else printf("IMPOSSIBLE");
        printf("\n");
    }

	return 0;
}
