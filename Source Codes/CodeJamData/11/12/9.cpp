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
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx; 

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

const int sz = 10111;
string words[sz];
int cnt[sz];

int xx = 0;

void rec(vector <int> cur, char *buf, int sum) {
    xx++;
    if (cur.size() == 0) return;
    if (*buf == 0) {
        db(*buf<<" "<<sum<<" "<<&buf[-24]);
        fore (it, cur) cnt[*it] = sum;
        fore (it, cur) db(sum<<" "<<words[*it]);
        return;
    }
    char zn = buf[0];
    map<int, vector<int> > zbiory;
    bool used = 0;
    fore (it, cur) {
        int curmask = 0;
        rep (j, (int)words[*it].size()) if (zn == words[*it][j]) {
            curmask |= 1 << j;
            used = 1;
        }
        zbiory[curmask].push_back(*it);
    }

    fore (it, zbiory) {
        int nsum = sum + (used && it->first == 0);
        rec(it->second, &buf[1], nsum);
    }
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    rep (i, n) { char buf[20];
        scanf("%s", buf);
        words[i] = buf;
    }
    rep (k, m) {
        rep (i, n) cnt[i] = 0;
        char buf[50];
        scanf("%s", buf);
        vector<int> le[12];
        rep (j, n) le[words[j].size()].push_back(j);
        rep (g, 12) rec(le[g], buf, 0);

        int best = 0;
        int bestcnt = 0;
        rep (i, n) if (bestcnt < cnt[i]) { bestcnt = cnt[i]; best = i; }
        rep (i, n) db(i<<" "<<words[i]<<" "<<cnt[i]);
        printf(" %s", words[best].c_str());
        db(xx);
       // exit(0);
    }
}

int main(int argc, char ** argv) {
    //freopen("1.in","r",stdin); 
    //freopen("2.in","r",stdin); 
    //freopen("3.in","r",stdin); 

    //freopen("../B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
    //freopen("../A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
    //freopen("../A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);

    freopen("../B-large.in","r",stdin); freopen("B-large.out","w",stdout);

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        cerr << "i" << " " << i << endl;
        printf("Case #%d:", i);
        solve();
        printf("\n");
        fflush(stdout);
        cerr.flush();
    }
    db(xx);
	return 0;
}

