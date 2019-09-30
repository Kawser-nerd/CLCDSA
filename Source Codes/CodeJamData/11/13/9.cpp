#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

#define pii complex<int>

int c[100];
int s[100];
int t[100];


const int sz = 90;
int used[sz];

void solve() {
    int n;
    int m;
    scanf("%d", &n);
    int idx = 0;
    rep (i, n) {
        scanf("%d%d%d", &c[idx], &s[idx], &t[idx]);
        idx++;
    }
    scanf("%d", &m);
    rep (i, m) {
        scanf("%d%d%d", &c[idx], &s[idx], &t[idx]);
        idx++;
    }
    int result = 0;
    fo (usedc, 0, n + m) {
        rep (i, sz) used[i] = 0;
        int myc = 0;
        int us = 0;
        int cards = n;
        int score = 0;
        int turns = 1;
        while (us < cards && turns > 0) {
            cards = min(cards, n + m);
            int cand = -1;
            rep (i, cards) if (used[i] == 0 && t[i] > 0) cand = i;
            if (cand >= 0) 
            { used[cand] = 1; us ++; cards += c[cand]; score += s[cand]; turns += t[cand]; }
            else {
                rep (i, cards) if (used[i] == 0 && myc < usedc && c[i] >= 1) {
                    if (cand == -1) cand = i;
                    if (s[cand] < s[i]) cand = i;
                }
                if (cand >= 0) 
                { myc++; used[cand] = 1; us ++; cards += c[cand]; score += s[cand]; turns += t[cand]; }
                else {
                    rep (i, cards) if (used[i] == 0) {
                        if (cand == -1) cand = i;
                        if (s[cand] < s[i]) cand = i;
                    }
                    if (cand >= 0) 
                    { used[cand] = 1; us ++; cards += c[cand]; score += s[cand]; turns += t[cand]; }
                    else break;
                }
            }
            cards = min(cards, n + m); turns--;
        }
        result = max(result, score);
    }
    printf("%d", result);
}

int main(int argc, char ** argv) {
    //freopen("1.in","r",stdin); 
    //freopen("2.in","r",stdin); 
    //freopen("3.in","r",stdin); 

    freopen("../C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
    //freopen("../C-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
    //freopen("../C-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);

    //freopen("../C-large.in","r",stdin); freopen("C-large.out","w",stdout);

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int tt;
    scanf("%d", &tt);
    fo (i, 1, tt) {
        cerr << "i" << " " << i << endl;
        printf("Case #%d: ", i);
        solve();
        printf("\n");
        fflush(stdout);
        cerr.flush();
    }
	return 0;
}

