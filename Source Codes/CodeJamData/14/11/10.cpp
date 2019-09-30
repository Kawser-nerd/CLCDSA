

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
#include <complex>
#include <cassert>

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
char buf[1000];

void solve() {
    vector<string> a, b;
    int n, l;
    scanf("%d%d", &n, &l);
    rep (i, n) {
        scanf("%s", buf);
        a.pb(buf);
        assert(a.back().size() == l);
    }
    rep (i, n) {
        scanf("%s", buf);
        b.pb(buf);
        assert(b.back().size() == l);
    }

    int res = 1e9;

    rep (i, n) {
        vector<bool> rev;
        int tmp = 0;
        rep (j, l) {
            rev.push_back(a[0][j] != b[i][j]);
            tmp += rev.back();
            db(rev.back());
        }
        assert(rev.size() == l);

        vector<string> left = a;
        vector<string> right = b;

        rep (j, n) rep (k, l) {
            if (rev[k]) left[j][k] ^= 1;
        }
        db(left[0]);
        db(right[0]);


        sort(all(left));
        sort(all(right));
        
        db(i);
        db((int)(left == right));

        if (left == right && tmp < res)
            res = tmp;
    }

    if (res == (int)1e9)
        printf("NOT POSSIBLE");
    else
        printf("%d", res);
}

int main(int argc, char ** argv) {
    //  freopen("../1.in","r",stdin); 
    //  freopen("../2.in","r",stdin); 
    //  freopen("../3.in","r",stdin); 
    //  freopen("../A-small.in","r",stdin); freopen("../A-small.out","w",stdout);
    //  freopen("../A-small-attempt0.in","r",stdin);freopen("../A-small-attempt0.out","w",stdout);
    //  freopen("../A-small-attempt1.in","r",stdin);freopen("../A-small-attempt1.out","w",stdout);
    //  freopen("../A-small-attempt2.in","r",stdin);freopen("../A-small-attempt2.out","w",stdout);
    //  freopen("../A-large.in","r",stdin); freopen("../A-large.out","w",stdout)

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        if (cond)
            cerr << __LINE__ << " " << i << endl;
        printf("Case #%d: ", i);
        solve();
        printf("\n");
        fflush(stdout);
        cerr.flush();
    }
	return 0;
}

