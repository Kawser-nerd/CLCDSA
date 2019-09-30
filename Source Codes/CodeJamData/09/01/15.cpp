#include <cstdio>
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

const int max_d = 5011;
const int max_l = 20;
int mask[max_d][max_l];

int main(int argc, char ** argv) {
    ios::sync_with_stdio(false);
    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int l, d, n;
    scanf("%d%d%d", &l, &d, &n);
    rep (i, d) {
	    rep (j, l) {
		    char x; scanf(" %c", &x);
		    mask[i][j] |= 1 << (x - 'a');
		    db(i<<" "<<mask[i][j]<<" "<<x<<" "<<i<<" "<<j);
	    }
    }
    rep (i, n) {
	    int cel[max_l] = {};
	    rep (j, l) {
		    char x; scanf(" %c", &x);
		    int &cur_mask = cel[j];
		    if (x != '(') {
			    cur_mask |= 1 << (x - 'a');
		    }
		    else {
			    while (scanf(" %c", &x) == 1) {
				    if (x == ')') break;
				    cur_mask |= 1 << (x - 'a');
			    }
		    }
	    }
	    int result = 0;
	    rep (k, d) {
		    int cnt = 0;
		    rep (j, l) if (cel[j] & mask[k][j]) cnt++; else break;
		    db(i<<" "<<k<<" "<<(cnt == l));
		    result += cnt == l;
	    }
	    printf("Case #%d: %d\n", i + 1, result);
    }
    return 0;
}

